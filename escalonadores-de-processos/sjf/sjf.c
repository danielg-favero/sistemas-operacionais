#include "sjf.h"

void sjf(Process *process, int n) {
    int i, j;
    Process aux;
    
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (process[i].time > process[j].time) {
                aux = process[i];
                process[i] = process[j];
                process[j] = aux;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (i == 0) {
            process[i].startTime = 0;
        }
        else {
            process[i].startTime = process[i - 1].startTime + process[i - 1].time;
        }
    }

    for (i = 0; i < n; i++) {
        process[i].endTime = process[i].startTime + process[i].time;
    }

    int totalTime = 0;
    for (i = 0; i < n; i++) {
        totalTime += process[i].startTime;
    }
    
    printf("Tempo medio de espera: %.2f\n", (float)totalTime / n);
}

void orderById(Process *process, int n) {
    int i, j;
    Process aux;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (process[i].pid > process[j].pid)
            {
                aux = process[i];
                process[i] = process[j];
                process[j] = aux;
            }
        }
    }
}

void printGranntDiagram(Process *process, int n, int totalTime) {
    orderById(process, n);
    int i, j, k = 0;
    int tempoPercorrido = 0;

    for (i = 0; i < n; i++) {
        printf("P%d -> ", process[i].pid);
        for (k = 0; k < process[i].startTime; k++) {
            printf("-");
        }

        for (k=0; k < process[i].time; k++) {
            printf("#");
        }

        for (k = process[i].startTime + process[i].time; k < totalTime; k++) {
            printf("-");
        }
        printf("\n");
    }
}