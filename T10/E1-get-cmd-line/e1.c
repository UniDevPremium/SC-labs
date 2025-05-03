#include "e1.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void get_cmd_line(char* argv[MAX_TOKENS]){
    // legge da stdin
    char buffer[MAX_LINE];
    if (fgets(buffer, MAX_LINE, stdin) == NULL) {
        argv[0] = NULL;
        return;
    }
    char *token = strtok(buffer, " \t\n");
    int count = 0;
    while(token != NULL && count < MAX_TOKENS){
        argv[count] = (char*)malloc(strlen(token) + 1);
        if(argv[count] != NULL) strcpy(argv[count], token);
        count++;
        token = strtok(NULL, " \t\n");
    }

    argv[count] = NULL;
}

