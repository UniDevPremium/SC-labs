#include "e3.h"

// La funzione my_strpbrk(s1, s2) deve restituire il puntatore alla prima 
// occorrenza in `s1` di un qualsiasi carattere presente nella stringa `s2` 
// oppure `NULL` se alcun carattere di s2 appare in `s1` prima che `s1` 
// stessa termini.

// scrivere la soluzione qui...

char *my_strpbrk(const char *s1, const char *s2){
    const char *t1 = s1;
    const char *t2 = s2;
    while(*t1){
        char c = *t1;
        while(*t2){
            if(c == *t2) return t1;
            t2++;
        }
        t2 = s2;
        t1++;
    }
    return 0;
}
