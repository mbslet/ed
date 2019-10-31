#include<stdio.h>
//#include "fila_int_tam_fixo.h"
//#include "fila_int_circular.h"
#include "fila_int_le_circular.h"

int main(){
    int opcao;
    inicializa_fila();
    int num, elem, cont = 0;
    while (1)
    {
        printf("\n\n 1 - Inserir n elementos na fila\n 2 - Remover n elementos na fila\n 3 - Imprimir a fila\n 4 - Reiniciar a fila\n 5 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:

            
            printf("Digite quantos elementos você deseja inserir:");
            scanf("%d", &num);
            
            for(int i = 0; i < num; i++){
                printf("Insira o elemento:");
                scanf("%d", &elem);
                if(elem < 0 || elem > 999){
                    printf("Elemento inválido, insira um elemento maior que 0 e menor que 999:");
                    scanf("%d", &elem);
                }//printf("%d\n", i);
                if(enfileira_fila(elem)){
                    cont++;
                }else{
                    printf("%d elementos foram inseridos na fila, mas %d não couberam\n", cont, (num-cont));
                    break;   
                }
            }
            break;
        case 2:
            puts("Digite quantos elementos você deseja remover:");
            scanf(" %d", &num);
            for (int i = 0; i < num; i++){
                if(desenfileira_fila(&elem)) printf("Elemento removido: %03d\n", elem);
                else puts("Não há elementos para serem removidos");
            }
            
            break;
        
        case 3:
            imprime_fila();
            break;
        
        case 4:
            destroi_fila();
            break;

        default:
            break;
        }
        if(opcao == 5) break;
    }

    return 0;
}

// gcc main.c -o main fila_int_tam_fixo.c1