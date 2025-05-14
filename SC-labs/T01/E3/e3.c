#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char * id;
    char * value;
    struct node * next;
} node_t;

static int count = 0;

node_t* add_node(node_t* l, char* value) {
    node_t* node = malloc(sizeof(node_t)); // qua allocato il blocco gestito male
    /*
    char id[16];
    sprintf(id, "ID_%d", count++);
    node->id = id;
    node->value = value;

    if (l != NULL)
        node->next = l;
   
    return node;
    */
    node->id = malloc(16);
    sprintf(node->id, "ID_%d", count++);
    node->value = malloc((strlen(value) + 1));
    strcpy(node->value, value);
    node->next = NULL;
    if (l != NULL) node->next = l;
    return node;
    /*
    Andavano allocati dinamicamente i campi della struttura
    per evitare che venissero liberati alla fine della funzione
    */
}

void print_list(node_t* head) {
    node_t* current = NULL;
    if (head != NULL) current = head;
    while (current != NULL) { // current è non inizializzato
        printf("%s\n", current->value);
        current = current->next;
    }
}

void delete_list(node_t * head) {
    node_t* current = head;
    node_t* next = NULL;

    while (current != NULL) {
        /*
        free(current);
        free(current->value); // lettura di memoria non valida (int)
        current = current->next; // lettura di memoria non valida (int)
        */
        free(current->value);
        free(current->id);
        next = current->next;
        free(current);
        current = next;
        /*
        Vanno liberati prima i campi dato
        poi salvato il next
        infine liberato il nodo
        */
    }
}

int main() {
    node_t* l;

    l = add_node(NULL, "Hello");
    l = add_node(l, " ");
    l = add_node(l, "World");
    l = add_node(l, "!");

    print_list(l);
    delete_list(l);

    printf("Risultato 1/1\n");
    return 0;
}