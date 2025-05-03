//SCRIVI LA SOLUZIONE QUI...
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "e2.h"

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


int do_shell(const char* prompt){
    if(!prompt || !*prompt) exit(1);
    char* argv[MAX_TOKENS];

    while(1){
        if (printf("%s", prompt) < 0) {
            perror("printf");
            exit(1);
        }
        for(int i = 0; i < MAX_TOKENS; i++) argv[i] = NULL;
        get_cmd_line(argv);
        if(argv[0] == NULL) continue;
        if(strcmp(argv[0], "quit") == 0){
            for(int i = 0; i < MAX_TOKENS; i++) free(argv[i]);
            exit(0);
        }

        pid_t pid = fork();
        if(pid < 0){
            perror("fork");
            for(int i = 0; i < MAX_TOKENS; i++) free(argv[i]);
            exit(1);
        } else if(pid == 0){
            if(execvp(argv[0], argv) == -1){
                fprintf(stderr, "unknown command %s\n", argv[0]);
                exit(1);
            }
        } else {
            if(wait(NULL) == -1){
                perror("wait");

            };
        }
    }
    
}

