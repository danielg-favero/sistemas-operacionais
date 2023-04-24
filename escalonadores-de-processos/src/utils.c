#include "utils.h"

int getTotalTime(Queue *queue) {
    int i;
    int totalTime = 0;

    for(i = 0; i < queue->length; i++){
        totalTime += queue->processes[i].time;
    }

    return totalTime;
}

void ganttDiagram(Queue *queue, int totalTime) {
    int i, j = 0;

    for (i = 0; i < queue->length; i++) {
        printf("P%d -> ", queue->processes[i].pid);
        for (j = 0; j < queue->processes[i].startTime; j++) {
            printf("-");
        }
        for (j=0; j < queue->processes[i].time; j++) {
            printf("#");
        }
        for (j = queue->processes[i].startTime + queue->processes[i].time; j < totalTime; j++) {
            printf("-");
        }
        printf("\n");
    }
}

void printProcesses(Process *process, int n) {
    printf("%-10s %-10s %-10s %-10s %-10s\n", "PID", "Priority", "Time", "Start Time", "End Time"); // Cabeçalho da tabela
    int i;
    for (i = 0; i < n; i++) {
        printf("%-10d %-10d %-10d %-10d %-10d\n", process[i].pid, process[i].priority, process[i].time, process[i].startTime, process[i].endTime);
        printf("-----------------------------------------------------\n");
    }
}

void orderById(Process *process, int n) {
    int i, j;
    Process aux;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (process[i].pid > process[j].pid) {
                aux = process[i];
                process[i] = process[j];
                process[j] = aux;
            }
        }
    }
}

void printGranntDiagram(Process *process, int n, int totalTime) {
    orderById(process, n);
    int i, k = 0;
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