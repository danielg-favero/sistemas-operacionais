#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE_PROCESSES 100

typedef struct Process Process;
typedef struct Queue Queue;

struct Process {
    int pid;
    int time;
    int priority;
    int startTime;
    int endTime;
};

struct Queue {
    Process *processes;
    int length;
};

Queue *startQueue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->processes = (Process *) malloc(MAX_SIZE_PROCESSES * sizeof(Process));
    queue->length = 0;

    return queue;
}

int insert(Queue *queue, Process process) {
    if(queue->length + 1 > MAX_SIZE_PROCESSES) return 0;

    queue->processes[queue->length] = process;
    queue->length += 1;

    return 1;
}

Process *unqueue(Queue *queue) {
    if(queue->length == 0) return 0;

    int i;
    Process *unqueuedProcess = &queue->processes[0];

    for(i = 0; i < queue->length - 1; i++){
        queue->processes[i] = queue->processes[i + 1];
    }

    queue->length--;

    return unqueuedProcess;
}

void fcfs(Queue *queue) {
    Process *currentProcess;
    int totalTime = 0;

    while(queue->length >= 0) {
        currentProcess = unqueue(queue);
    }
}

void printQueue(Queue *queue) {
    int i;

    printf("\nPID\tTime\tPriority\n");
    for(i = 0; i < queue->length; i++){
        printf("%d\t%d\t%d\n", queue->processes[i].pid, queue->processes[i].time, queue->processes[i].priority);
    }
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
        process.priority = priority;

        printf("\n");
        insert(queue, process);

        printQueue(queue);
    }


    return 0;
}