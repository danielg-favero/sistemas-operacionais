#include "lib/utils.h"

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

    return 0;
}