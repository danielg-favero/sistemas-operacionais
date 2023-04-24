#include "../process/process.h"

typedef struct Queue Queue;

struct Queue {
    Process *processes;
    int length;
};

void printQueue(Queue *queue);
Queue *startQueue();
int insert(Queue *queue, Process process);
Process unqueue(Queue *queue);
Process removeFromQueue(Queue *queue, int index);