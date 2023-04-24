#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_PROCESSES 100

typedef struct Process Process;
typedef struct Queue Queue;

struct Process {
    int pid;
    int time;
    int priority;
    int startTime;
    int endTime;
    int executionTime;
};

struct Queue {
    Process *processes;
    int length;
};

void printQueue(Queue *queue) {
    int i;

    printf("\nTotal de processos: %d\n", queue->length);
    printf("\nPID\tTime\tPriority\n");
    for(i = 0; i < queue->length; i++){
        printf("%d\t%d\t%d\n", queue->processes[i].pid, queue->processes[i].time, queue->processes[i].priority);
    }
}

Queue *startQueue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->processes = (Process *) malloc(MAX_SIZE_PROCESSES * sizeof(Process));
    queue->length = 0;

    return queue;
}

int insert(Queue *queue, Process process) {
    if(queue->length + 1 > MAX_SIZE_PROCESSES) return 0;

    queue->processes[queue->length] = process;
    queue->length++;

    return 1;
}

Process unqueue(Queue *queue) {
    int i;
    Process unqueuedProcess = queue->processes[0];

    for(i = 0; i < queue->length - 1; i++){
        queue->processes[i] = queue->processes[i + 1];
    }

    queue->length--;


    return unqueuedProcess;
}

Process removeFromQueue(Queue *queue, int index) {
    int i;
    Process unqueuedProcess = queue->processes[index];

    for(i = index; i < queue->length - 1; i++){
        queue->processes[i] = queue->processes[i + 1];
    }

    queue->length--;

    return unqueuedProcess;
}

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

float fcfs(Queue *queue) {
    Process currentProcess;
    Queue *endedProcesses = startQueue();
    int totalProcess = queue->length;
    int totalTime = 0;
    int remainingTime = 0;
    int i;
    float avarageTime = 0;
    int sum = 0;

    while(queue->length > 0) {
        currentProcess = unqueue(queue);
        remainingTime = currentProcess.time;

        currentProcess.startTime = totalTime;
        while(remainingTime > 0) {
            totalTime++;
            remainingTime--;
        }
        
        sum += currentProcess.startTime;
        
        insert(endedProcesses, currentProcess);
    }


    avarageTime = (float)sum / totalProcess;

    printQueue(endedProcesses);
    ganttDiagram(endedProcesses, totalTime);

    return avarageTime;
}

float roundRobin(Queue *queue, int timeSlice) {
    Process currentProcess;
    Process removedProcess;
    Queue *endedProcesses = startQueue();
    int currentTime = 0;
    int queueLength = queue->length;
    int totalTime = getTotalTime(queue);
    int processRemainingTime;
    int i = 0, j = 0, k = 0;
    int sum = 0;

    char ganttDiagram[queueLength][totalTime + 1];
    memset(ganttDiagram, 0, sizeof(ganttDiagram));

    while(queue->length > 0) {
        currentProcess = queue->processes[i];

        processRemainingTime = queue->processes[i].time;
                
        for(j = 0; j < queueLength; j++) {
            if(processRemainingTime <= timeSlice){
                k = processRemainingTime;
            } else {
                k = timeSlice;
            }

            while(k > 0) {
                if(j == currentProcess.pid - 1){
                    strcat(ganttDiagram[j], "#");
                } else {
                    strcat(ganttDiagram[j], "-");
                }
                k--;
            }
        }

        if(processRemainingTime <= timeSlice){
            queue->processes[i].time = 0;
            currentTime += processRemainingTime;
        } else {
            queue->processes[i].time = processRemainingTime - timeSlice;
            currentTime += timeSlice;
        }

        processRemainingTime = queue->processes[i].time;

        if(processRemainingTime == 0){
            removedProcess = removeFromQueue(queue, i);
            removedProcess.endTime = currentTime;

            sum += currentTime - removedProcess.executionTime;

            insert(endedProcesses, removedProcess);

            i--;
        }

        if(i >= queue->length - 1) {
            i = 0;
        } else {
            i++;
        }
    }

    for(i = 0; i < queueLength; i++) {
        printf("P%d -> ", i);
        for(j = 0; j < totalTime; j++) {
            printf("%c", ganttDiagram[i][j]);
        }
        printf("\n");
    } 

    return (float)sum / queueLength;
}

int main(){
    Queue *queue = startQueue();
    int n;
    int i;

    printf("Informe a quantidade de processos: ");
    scanf("%d", &n);

    printf("Insira os processos na fila:\n");
    for(i = 0; i < n; i++){
        Process process;
        int pid;
        int time;
        int priority;

        printf("%d) PID: ", i + 1); 
        scanf("%d", &pid);  

        printf("%d) Time: ", i + 1);   
        scanf("%d", &time);  

        printf("%d) Priority: ", i + 1);   
        scanf("%d", &priority);  

        process.pid = pid;
        process.time = time;
        process.executionTime = time;
        process.priority = priority;

        printf("\n");
        insert(queue, process);
    }

    printQueue(queue);
    // printf("\nTempo médio FCFS: %.2f\n\n", fcfs(queue));
    printf("\nTempo médio RR: %.2f\n\n", roundRobin(queue, 3));

    return 0;
}