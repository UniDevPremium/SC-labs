# Programma - Sistemi di Calcolo

_prof. Querzoni, 2024-25_

Integrato da [Diario delle Lezioni](https://season-lab.github.io/SC/DiarioLezioni)

## 1. Introduzione

### 1.1 Macchina di Von Neumann

### 1.2 C vs ASM vs bin

### 1.3 Pipeline compilazione di _gcc_

### 1.4 Debugging via _gdb_ e _valgrind_

## 2. IA32 AT&T

### 2.1 Intro sintassi AT&T

2.1.1 Direttiva _.globl_
2.1.2 Suffissi _b_, _w_, _l_
2.1.3 Istruzioni unarie e binarie
2.1.4 Operandi

### 2.2 Registri

### 2.3 Assegnamento via _MOV_

### 2.4 Ritorno via _RET_

### 2.5 Operatori logici e aritmetici

2.5.1 Logici

+ _NOT_
+ _AND_
+ _OR_
+ _XOR_

2.5.2 Aritmetici

+ _NEG_
+ _ADD_
+ _SUB_
+ _IMUL_
+ _INC_
+ _DEC_
+ _DIV_

### 2.6 Calcolo espressioni

### 2.7 Accesso parametri di funzioni

2.7.1 _(%esp)_ e offset
2.7.2 Layout _caller-callee_
2.7.3 Indirizzo di ritorno

### 2.8 Istruzioni di Salto

2.8.1 Salto incondizionato via _JMP_
2.8.2 Salto condizionato via _Jcc_
2.8.3 Condition Code e _EFLAGS_
2.8.4 Pattern _SUB-Jcc_, _CMP-Jcc_, _TEST-Jcc_

### 2.9 Puntatori

2.9.1 Array
2.9.2 Stringhe

### 2.10 Chiamate e ritorno da funzione

2.10.1 _CALL_
2.10.2 _RET_
2.10.3 Passaggio parametri da stack
2.10.4 Registri _caller-saved_ e _calle-saved_
2.10.5 _PUSH_ e _POP_

### 2.11 Conversioni

2.11.1 _MOVS_
2.11.2 _MOVZ_

### 2.12 Variabili locali

2.12.1 Salvataggio nello stack e memoria
2.12.2 Calcolo indirizzi ed espressioni via _LEA_
2.12.3 Allineamento in memoria
2.12.4 Struct C

### 2.13 Espressioni booleane

2.13.1 _SETcc_
2.13.2 Overflow
2.13.3 Assegnamento condizionato _CMOVcc_

### 2.14 Divisioni intera e potenze di 2

2.14.1 Shift logico via _SHL_, _SHR_
2.14.2 Shift aritmetico via _SAL_, _SAR_
2.14.3 Divisione intera via _IDIV_
2.14.4 Vincoli su alcune operazioni


## 3. Linguaggio C

### 3.4 Sistemi Operativi

4.6.1 Panoramica
4.6.2 Modalità di esecuzione: utente vs supervisore
4.6.3 _POSIX_ vs libreria C vs _system calls_
4.6.4 Comando _man_, tool _ltrace_ e _strace_

### 3.1 Terminazione programmi

3.1.1 _return_
3.1.2 _exit_
3.1.3 _/_exit_
3.1.4 _abort_
3.1.5 _assert_
3.1.6 Gestori _atexit_

### 3.2 Gestione errori

3.2.1 Espressioni di tipo
3.2.2 Errori recuperabili
3.2.3 Errori irrecuperabili via _errno_, _perror_

### 3.3 Funzioni di libreria

3.3.1 Funzioni sulle stringhe
3.3.2 Funzioni su memoria
3.3.3 Funzioni sui file
3.3.4 Funzioni di ordinamento e ricerca
3.3.5 Funzioni matematiche

## 4. Calcolatore

### 4.1 Panoramica x86_64

### 4.2 Prestazioni

4.2.1 Latenza
4.2.2 Throughput
4.2.3 Spazio
4.2.3 Energia
4.2.4 Speedup e legge di Amdahl
4.2.5 Profilazione manuale via _gprof_

### 4.3 Intro Ottimizzazione

4.3.1 Livello di intervento
4.3.2 Legge di Moore

### 4.4 Ottimizzazioni work

4.4.1 _Constant Folding_
4.4.2 _Constant Propagation_
4.4.3 _Common Subexpression Elimination, CSE_
4.4.4 _Loop-Invariant Code Motion, LICM_
4.4.5 _Loop Unrolling_
4.4.6 _Function Inlining_

### 4.5 Ottimizzazioni costo istruzioni

4.5.1 _Register Allocation_
4.5.2 _Operator Strength Reduction, OSR_
4.5.3 _Memory Alignment_












