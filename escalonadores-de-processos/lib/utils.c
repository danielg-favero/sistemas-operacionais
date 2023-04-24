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