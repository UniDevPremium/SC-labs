// Inserisci qui il C equivalente...
#include <stdlib.h>
#include "e2.h"

int list_equal(const node_t *l1, const node_t *l2){
    const node_t *a = l1;
    const node_t *c = l2;

T:
    if (a == 0) goto E;
    if (c == 0) goto E;
    short d = (*a).elem;
    if (d == (*c).elem) goto F;
    a = 0;
    goto R;

F:
    a = (*a).next;
    c = (*c).next;
    goto T;

E:
    char al = a == 0;
    char cl = c == 0;
    al = al & cl;
    a = (int)al;

R:
    return a;
}