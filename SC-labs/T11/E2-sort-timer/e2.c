#include "e2.h"
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>


static volatile int i = 0;
static int max = 1;
volatile sig_atomic_t done = 0;

static void handle_signal(int signo){
    if(max > 0){
        // calcola e stampa la percentuale corrente
        float percent = 100.0 * i / max;
        printf("%.1f%%\n", percent);
    }
}

static void do_sort(int *v, int n) {
    int j;
    for (i=0; i<n; ++i){
        for (j=1; j<n; ++j){
            if (v[j-1] > v[j]) {
                int tmp = v[j-1];
                v[j-1] = v[j];
                v[j] = tmp;
            }
        }
    }
}

void sort(int *v, int n) {
    // completare con gestione segnali...
    struct sigaction sa;
    struct itimerval timer;

    max = n;

    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if(sigaction(SIGALRM, &sa, NULL) == -1){
        perror("Errore configurazione gestore del segnale");
        return;
    };


    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = 100000000; // 1s
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 100000000; // 100ms

    if(setitimer(ITIMER_REAL, &timer, NULL) == -1){
        perror("Errore impostazione timer");
        return;
    }

    do_sort(v, n);

    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;
    setitimer(ITIMER_REAL, &timer, NULL);
}

