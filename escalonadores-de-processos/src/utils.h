#include "queue.h"

int getTotalTime(Queue *queue);
void ganttDiagram(Queue *queue, int totalTime);
void printProcesses(Process *process, int n);
void orderById(Process *process, int n);
void printGranntDiagram(Process *process, int n, int totalTime);