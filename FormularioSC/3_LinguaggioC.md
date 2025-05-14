
# 3. Linguaggio C

## 3.1 Sistemi Operativi

3.1.1 Panoramica
3.1.2 Modalità di esecuzione: utente vs supervisore
3.1.3 _POSIX_ vs libreria C vs _system calls_

### 3.1.4 Comando _man_, tool _ltrace_ e _strace_

Il comando `man` permette di leggere la documentazione di ogni istruzioni, vi sono 3 sezioni fondamentali:

+ comandi del terminale, come cd o ls
+ system calls, come read() o write()
+ funzioni di libreria C standard, come printf() o malloc()

Il comando `strace` traccia tutte le system call effettuate dal processo monitorato:

```
strace <eseguibile>
```

I flag più comuni sono:

+ `-o <file.txt>` : salva output in file.txt
+ `-e trace=<open,write,..>` : filtra le system call desiderate
+ `-p <pid>` : monitora un processo già in esecuzione
+ `-f` : monitora anche i processi figli
+ `-t` : mostra i timestamp
+ `-c` : fornisce un riepilogo statistico

Il comando `ltrace` traccia tutte le chiamate a funzioni di librerie C effettuate dal processo monitorato:

```
ltrace <eseguibile>
```

I flag più comuni sono:

+ `-o <file.txt>` : salva output in file.txt
+ `-e trace=<malloc,printf,..>` : filtra chiamate a funzioni desiderate
+ `-l <lib>` : filtra le chiamate per libreria
+ `-f` : monitora anche i processi figli
+ `-t` : mostra i timestamp
+ `-c` : fornisce un riepilogo statistico


### 3.1 Terminazione programmi

Ogni programma ha necessità di terminare con un __return code__, un intero che descrive la modalità di terminazione del processo.

Generalmente vale:

+ nessun errore : return code = 0
+ qualche errore : return code != 0

Il return code può essere generato in 3 modi:

+ nel main, dopo l'ultima istruzione
+ tramite exit(code)
+ tramite abort(), dedicato agli errori

La terminazione si gestisce tramite una o più funzioni dette _exit handlers_

```
#include <stdlib.h>

int atexit(void (*handler)(void))
```

L'handler legge a destra se può, altrimenti a sinistra (?)


3.1.1 _return_
3.1.2 _exit_
3.1.3 _/_exit_
3.1.4 _abort_
3.1.5 _assert_
3.1.6 Gestori _atexit_

## 3.2 Gestione errori

3.2.1 Espressioni di tipo
### 3.2.2 Errori recuperabili

Sono tali che possono essere gestiti senza terminare il programma

3.2.3 Errori irrecuperabili via _errno_, _perror_

### 3.3 Funzioni di libreria

3.3.1 Funzioni sulle stringhe
3.3.2 Funzioni su memoria
### 3.3.3 Funzioni sui file

Sono le funzioni usate per la __gestione di stream__, per _stream_ si intende un astrazione che rappresenta un flusso di byte.

Quando viene avviato un programma da OS vengono assegnati 3 stream di deafult:

+ `stdin`, input stream
+ `stdout`, output stream generico
+ `stderr`, output stream dedicato ai messaggi d'errore

Di default, l'input stream è assegnato alla tastiera, mentre gli output stream sono assegnati al terminale.

Per gestire i file si usa la struct di libreria `FILE`.
Le modalità di apertura sono le seguenti :

+ _r_, read per leggere
+ _w_, write per sovrascivere
+ _a_, append per aggiungere
+ _rb_, _ab_, _wb_, per esecuzione su byte

```
FILE* fopen(const char* path, const char* mode);
```
dove:

+ `path` è il percorso del file system a partire da root
+ `mode` è la modalità d'apertura

La struct FILE contiene un campo usato come flag d'errore.

```
int ferror(FILE* f);
```

restituisce != 0 se è stato già settato il flag d'errore di f.

```
void clearerr(FILE* f);
```

setta a 0 il flag d'errore di f.

```
int fclose(FILE* f);
```

```
int fprintf(FILE* f, const char* format, ...);
```

```
int fscanf(FILE* f, const char* format, ...);
```

```
char* fgets(char* str, int size, FILE* f);
```

copia size caratteri da f in str.

```
size_t fread(void *ptr, size_t size, size_t n, FILE* f);
```

copia n*size bytes da f in ptr.

```
size_t fwrite(const void *ptr, size_t size, size_t n, FILE* f);
```

copia n*size bytes da ptr in f

```
int feof(FILE* f);
```

restituisce 0 solo se il puntatore f ha raggiunto la fine del file.

```
int fseek(FILE* f, long offset, int where);
```

sposta il puntatore f di offset bytes a partire da where, che è tra:

+ `SEEK_CUR` -> posizione corrente
+ `SEEK_END` -> fine del file
+ `SEEK_SET` -> inizio del file

```
long ftell(FILE* f);
```

restituisce lo scostamento di f da SEEK_SET.


__SYSTEM CALLS__

Le librerie che permettono le system calls sono:

```
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
```


```
#include <fcntl.h>

int open(const char* path, int flags, mode_t mode);
```

restituisce un file descriptor, accetta percorso assoluto o relativo, usa i flags per gestire la modalità di apertura dello stream e mode per i permessi associati al file

```
ssize_t write(int fd, const void* buf, size_t count);
```

copia count bytes da buf nel file rappresentato da fd.

```
ssize_t read(int fd, void* buf, size_t count);
```

copia count bytes dal file rappresentato da fd in buf.

```
off_t lseek(int fd, off_t offset, int where);
```

calcola l'indirizzo in fd con offset partendo da where.

```
int close(int fd);
```

interrompe la gestione dello stream liberando le risorse.













### 3.3.4 Funzioni di ordinamento e ricerca

La funzione di __ordinamento__ standard è `qsort`, ordina un generico array di input tramite quicksort, con side-effect. 
Necessita di una funzione di comparazione per il generico tipo indicizzato.

```
#include <stdlib.h>

void qsort(
    void* head,
    size_t n,
    size_t dim,
    int (*comparator)(const void* a, const void* b)
);
```

dove:

+ `void* head` è il puntatore all'array da ordinare
+ `size_t n` è il numero di elementi da ordinare
+ `size_t dim` è la dimensione in byte del tipo indicizzato
+ `int (*comparator)(const void* a, const void* b)` è una funzione che restituisce un intero negativo se a precede b, 0 se a == b e positivo altrimenti

La funzione di __ricerca__ standard è `bsearch`, cerca un elemento in un array.

```
#include <stdlib.h>

void bsearch(
    const void* key,
    void* head,
    size_t n,
    size_t dim,
    int (*comparator)(const void* a, const void* b)
);
```

dove `const void* key` punta all'elemento da cercare, altri parametri come qsort.


### 3.3.5 Funzioni matematiche

Sono contenute nella libreria `math.h` ed è necessario compilare con il flag `-lm` per usarle.

```
#include <math.h>

double sqrt(double x);
double exp(double x);
double log(double x);
double sqr(double x);
```
