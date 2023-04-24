// #include "rr.h"
// #include "fcfs.h"
// #include "sjf.h"
#include "priority.h"

int main(){
     int n, i, totalTime = 0;
    Process *process;
    printf("Digite o numero de processos: ");
    scanf("%d", &n);
    process = (Process *)malloc(n * sizeof(Process));
    for (i = 0; i < n; i++)
    {
        printf("Digite o PID, prioridade e o tempo do processo (ex: 1 1 3):");
        scanf("%d %d %d", &process[i].pid, &process[i].priority, &process[i].time);
        process[i].startTime = 0;
        process[i].endTime = 0;
        totalTime += process[i].time;
    }
    printf("----------------------------\n");
    priorityFunction(process, n);

    printf("----------------------------\n");

    printProcesses(process, n);

    printGranntDiagram(process, n, totalTime);
    // Queue *queue = startQueue();
    // int n;
    // int i;

    // printf("Informe a quantidade de processos: ");
    // scanf("%d", &n);

    // printf("Insira os processos na fila:\n");
    // for(i = 0; i < n; i++){
    //     Process process;
    //     int pid;
    //     int time;
    //     int priority;

    //     printf("%d) PID: ", i + 1); 
    //     scanf("%d", &pid);  

    //     printf("%d) Time: ", i + 1);   
    //     scanf("%d", &time);  

    //     printf("%d) Priority: ", i + 1);   
    //     scanf("%d", &priority);  

    //     process.pid = pid;
    //     process.time = time;
    //     process.executionTime = time;
    //     process.priority = priority;

    //     printf("\n");
    //     insert(queue, process);
    // }

    // printQueue(queue);
    // printf("\nTempo médio FCFS: %.2f\n\n", fcfs(queue));
    // printf("\nTempo médio RR: %.2f\n\n", roundRobin(queue, 3));

    return 0;
}