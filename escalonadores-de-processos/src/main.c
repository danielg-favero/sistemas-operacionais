#include "algorithms.h"

int main(){
    int opcao;
    
    printf("1) FCFS\n");
    printf("2) SJF\n");
    printf("3) Prioridades\n");
    printf("4) RR\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    while(opcao != -1){
        switch(opcao) {
            case 1:
                executeFcfs();
                break;
            case 2:
                executeSjf();
                break;
            case 3:
                executePriority();
                break;
            case 4:
                executeRR();
                break;
            default:
                printf("Opção inválida!\n");
        }
    }

    return 0;
}