// Scrivere la soluzione qui...
#include "e2.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// struct booking {
// 	char * surname;  
// 	int places;		 
// 	char * time;     
// 	struct booking * next;
// };

struct booking * getBook(char *cognome, char *strposti, char *orario){
    struct booking *b = (struct booking *)malloc(sizeof(struct booking));
    if(b == NULL) return NULL;

    b->surname = strdup(cognome);
    if(b->surname == NULL){
        free(b);
        return NULL;
    }

    b->places = atoi(strposti);

    b->time = strdup(orario);
    if(b->time == NULL){
        free(b->surname);
        free(b);
        return NULL;
    }

    b->next = NULL;

    return b;
}

void getBookingsAfterTime(struct booking ** list, const char * data, int size, const char * time){
    int n = size / 37;
    *list = NULL;
    struct booking *last = NULL;

    // trovo primo record con tempo uguale o maggiore
    for(int i = 0; i < n; i++){
        const char *record = data + (i * 37);

        char cognome[31];
        char strposti[3];
        char orario[6];

        strncpy(cognome, record, 30);
        cognome[30] = '\0';

        strncpy(strposti, record + 30, 2);
        strposti[2] = '\0';

        strncpy(orario, record + 32, 5);
        orario[5] = '\0';

        // rimuovi padding
        int j;
        for(j = 29; j >= 0 && cognome[j] == '_'; j--){
            cognome[j] = '\0';
        }
        for(j = 1; j >= 0 && strposti[j] == '_'; j--){
            strposti[j] = '\0';
        }

        if(strcmp(orario, time) >= 0) {
            // aggiungo a list
            struct booking *b = getBook(cognome, strposti, orario);

            if(*list == NULL){
                *list = b;
            } else {
                last->next = b;
            }
            last = b;
        }
    }
}