#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Process Process;

struct Process {
    int pid;
    int time;
    int priority;
    int startTime;
    int endTime;
    int executionTime;
};