# 4. Calcolatore

## 4.1 Panoramica x86_64

## 4.2 Prestazioni

Abbiamo bisogno di definire grandezze misurabili che rappresentino le prestazioni di ogni programma. 

Bisogna ricordare che l'architettura del calcolatore è tale che le operazioni hanno maggiori prestazioni se eseguite vicino alla CPU, e maggiori risorse disponibili se eseguite lontato da essa.

### 4.2.1 Latenza

La __latenza__ è il tempo necessario per eseguire un operazione

### 4.2.2 Throughput

Il __throughput__ è il numero di operazioni comppletate in un unità di tempo

### 4.2.3 Spazio

Lo __spazio__ è la memoria utilizzata.

### 4.2.3 Energia

L'__energia__ è il consumo di energia elettrica.

### 4.2.4 Speedup e legge di Amdahl

Il miglioramento prestazionale si misura come __speedup__ adimensionale:

> SPEEDUPx = T / T' = S

dove:

+ T è la latenza non ottimizzata
+ T' è la latenza ottimizzata

allora lo speedup è S.

La __legge di Amdahl__ ci permette di calcolare lo speedup complessivo di un programma a fronte dell'ottimizzazione di solo una parte di esso.

Sia un programma P composta da due moduli A e B, con latenza complessiva T e sapendo che A ha latenza $\alpha T$, quindi B avrà latenza $\alpha T$, ipotizziamo di poter ottimizzare A con uno speedup K.

La latenza ottimizzata à:

$$T' = T_A' + T_B'= \frac{T_A'}{K} + T_B = \frac{\alpha T}{K} + (1-\alpha)T = (\frac{\alpha}{K} + 1 - \alpha)T$$

Lo speedup complessivo di P sarà:

$$S = \frac{T}{T'} = \frac{T}{(\alpha/K + 1 - \alpha)T} = \frac{1}{\alpha/K + 1 - \alpha}$$

Possiamo allora calcolare lo __speedup teorico massimo__:

$$\lim_{K\to\infty}\frac{1}{\alpha/K + 1 - \alpha}=\frac{1}{1-\alpha}$$

### 4.2.5 Profilazione delle prestazioni

Consiste nel calcolo della latenza di ogni modulo di un programma, si può fare manuale o automatica:

+ _manuale_, tramite instrumentazione manuale del codice
+ _automatica_, instrumentazione svolta da tool

I limiti relativi allo strumento sono:

+ latenza della misurazione
+ risoluzione dello strumento

__N.B.__ La misurazione di T con uno strumento A è significativa solo se la risoluzione di A è superiore a T, e se la latenza della misurazione influisce sui risultati in modo trascurabile.

La profilazione __automatica__ si fa con il tool _gprof_, che usa cosi:

1. Compilare il codice target con flag `-pg`
2. Eseguire il programma
3. Visualizza output con `gprof <nome_programma>`


## 4.3 Intro Ottimizzazione

L'__ottimizzazione__ consiste nel modificare un programma in modo da minimizzare in esecuzione l'uso delle risorse disponibili, cercando di massimizzare le prestazioni e senza alcun impatto sulla correttezza.

Le questioni sono:

+ come posso valutare l'impatto di una ottimizzazione?
+ come misuro le prestazioni di un programma?
+ come si scelgono le parti che posso/voglio ottimizzare?
+ come si identificano gli _hot spots_ meritevoli di ottimizzazione?

### 4.3.1 Livello di intervento

Possiamo ottimizzare a due livelli, algoritmo e implementazione.

__Algoritmo__
Il progettista o programmatore sceglie l'algoritmo con il costo computazionale minore

+ PRO: impatto significativo sulle prestazioni
+ CONTRO: non sempre è possibile ed può richiedere un implementazione ad hoc

__Implementazione__
Il compilatore o il programmatore ottimizza il codice che implementa l'algoritmo scelto

+ PRO: parzialmente automatica ed economica
+ CONTRO: possono essere platform-dependent

Si classificano anche in ottimizzazioni _work_ e _di costo_:

+ ottimizzazione __work__, riduce il numero di istruzioni da eseguire
+ ottimizzazione __costo__, scelgo l'alternativa che impiega meno tempo alla CPU

Si imposta il grado di ottimizzazione a tempo di compilazione con i seguenti flag:

+ `-o` : default, non applica ottimizzazione
+ `-o1` : ottimizza
+ `-o2` : ottimizza+
+ `-o3` : ottimizza++
+ `-os` : ottimizza lo spazio
+ `-og` : ottimizza, preservando dove possibile i simboli di debug

4.3.2 Legge di Moore

## 4.4 Ottimizzazioni work

Le ottimizzazioni __work__ riducono il numero di istruzioni eseguite.

### 4.4.1 _Constant Folding_

Sono precalcolate le espressioni di valori costanti, applicata anche con -o.

```
int f(){
    return 8 + (14/2) * 3;
}
```

diventa

```
int f(){
    return 29;
}
```

### 4.4.2 _Constant Propagation_

I valori costanti vengono propagati nel codice quando possibile.

```
int x;
int f(){
    x = 8;
    return x - 2;
}
```

diventa

```
int x;
int f(){
    x = 8;
    return 8 - 2;
}
```

Utile prima del constant folding.

### 4.4.3 _Common Subexpression Elimination, CSE_

Memorizza e sostituisce occorrenze multiple di una sotto espressione.

```
int f(int x, int y){
    return (x+y) * (x+y);
}
```

diventa

```
int f(int x, int y){
    int z = x + y;
    return z * z;
}
```

### 4.4.4 _Loop-Invariant Code Motion, LICM_

Sposta fuori da un ciclo le espressioni che non dipendono dal ciclo stesso.

```
int f(int x, int n){
    int s = 1;
    for(; n > 0; n--)
        s += 7 + x;
    return s;
}
```

diventa

```
int f(int x, int n){
    int s = 1;
    int z = 7 + x;
    for(; n > 0; n--)
        s += z;
    return s;
}
```

Anche chiamate a funzioni possono essere la parte spostata fuori dal ciclo.

### 4.4.5 _Loop Unrolling_

Dato un ciclo con un numero di iterazioni noto, le riduce o elimina del tutto, srotola il ciclo.

```
int f(){
    int a = 0;
    for(int i = 0; i < 10; i++)
        a += 1;
    return a;
}
```

diventa

```
int f(){
    int a = 0;
    a++;
    ... x 10
    a++;
    return a;
}
```

Nei casi comuni il numero di iterazioni non è noto, diciamo sia una variabile n, allora si calcola k come il massimo divisore di n, e si divide il ciclo in blocchi di k iterazioni srotolate, i resti passi (al massimo k-1) sono eseguiti in un ciclo semplice.


### 4.4.6 _Function Inlining_

Dove possibile sostituisce la chiamata a funzione con il corpo della stessa.

```
int sqr(int x){ return x * x;}
void f(int *v, int n){
    int i;
    for(i = 0; i < n; i++)
        v[i] = sqr(i);
}
```

diventa

```
int sqr(int x){return x*x;}
void f(int *v, int n){
    int i;
    for(i = 0; i < n; i++)
        v[i] = i * i;
}
```



## 4.5 Ottimizzazioni costo istruzioni

Scelgono l'alternativa che richiede meno tempo alla CPU.

### 4.5.1 _Register Allocation_

Massimizza l'uso dei registri.

### 4.5.2 _Operator Strength Reduction, OSR_

Sostituisce una istruzione con un altra equivalente ma meno costosa.

```
x / 8 -> x >> 3
x * 64 -> x << 6
x * 2 -> x + x
x * 15 -> (x << 4) - x
```

### 4.5.3 _Dead Code Elimination_

Elimina il codice non raggiungibile.

### 4.5.4 Riduzione spazio di allocazione struct

Il programmatore può riordinare i campi della struct dal più grande al più piccolo per minimizzare il padding interno essa, non varia l'allineamento complessivo.

### 4.5.5 _Memory Alignment_

Ogni dato da N byte viene salvato in memoria ad un indirizzo x multiplo di N.

