// Scrivi la soluzione qui...
#include <stdlib.h>
#include "e1.h"

int _strcmp(const char *a, const char *b){
    while(*a && (*a == *b)){
        a++;
        b++;
    }
    return *(const unsigned char *)a - *(const unsigned char *)b;
}

int _prscmp(const void *a, const void *b){
    const person_t *pa = (const person_t *)a;
    const person_t *pb = (const person_t *)b;

    return _strcmp(pa->name, pb->name);
}

void sort_people(person_t p[], size_t nel){
    qsort(p, nel, sizeof(person_t), _prscmp);
}

person_t *find_person(char *key, person_t sorted[], size_t nel){
    person_t target = {key, 0};

    return (person_t *)bsearch(&target, sorted, nel, sizeof(person_t), _prscmp);
}