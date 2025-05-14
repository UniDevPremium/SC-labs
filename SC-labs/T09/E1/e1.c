#include "e1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void elabora(char* buffer, person_t** out, int minAge){
    // campi dati da CSV
    char nome[49], cognome[49], data[11], phd[4];
    int giorno, mese, anno;
    // puntatore a persona
    person_t* p;
    // parsing riga
    if(sscanf(buffer, "%48[^,],%48[^,],%10[^,],%3s", nome, cognome, data, phd) != 4) return;
    // parsing data
    if(sscanf(data, "%d-%d-%d", &giorno, &mese, &anno) != 3) return;
    // condizione
    if(anno < minAge) return;
    // alloco nuovo nodo
    p = (person_t*)malloc(sizeof(person_t));
    if(!p) return;
    // copio campi nel nodo
    p->name = strdup(nome);
    p->surname = strdup(cognome);
    p->year = anno;
    p->has_phd = (strcmp("yes", phd) == 0) ? 1 : 0;
    p->next = NULL;
    // aggiungo alla lista in testa
    if(*out == NULL) *out = p;
    else { // o in coda
        (*out)->next = p;
    }
}

int parseCSV(const char* file, person_t** out, int minAge) {

    FILE *f = fopen(file, "r");
    if(!f){
        // se il file non esiste *out NULL e ret -1
        *out = NULL;
        return -1;
    }

    // inizializzo lista vuota e buffer riga
    person_t* head = NULL;
    person_t** tail = &head;
    char buffer[65];

    while(fgets(buffer, sizeof(buffer), f)){
        // elaboro riga per riga
        elabora(buffer, tail, minAge);
        while(*tail) tail = &(*tail)->next; // avanza tail
    }
    // chiudo file
    fclose(f);
    // copio head in *out
    *out = head;
    return 0;
}