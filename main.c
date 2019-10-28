#include<stdio.h>
#include "fila_int_tam_fixo.h"

int main(){
    int opcao;
    
    while (1)
    {
        printf("\n\n 1 - Inserir n elementos na fila\n 2 - Remover n elementos na fila\n 3 - Imprimir a fila\n 4 - Reiniciar a fila\n 5 - Sair")
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            inicializa_fila();
            int num, elem, cont = 0;
            printf("“Digite quantos elementos você deseja inserir:")
            scanf("%d", &num);
            
            for(int i = 0; i < num; i++){
                printf("Insira o elemento:");
                scanf("%d", &elem);
                if(elem < 0 || elem > 999){
                    printf("Elemento inválido, insira um elemento maior que 0 e menor que 999:");
                    scanf("%d", &elem);
                }
                enfileira_fila(elem);
                cont++;
                if(fila_cheia()){
                    printf("%d elementos foram inseridos na fila, mas %d não couberam", cont, (num-cont));
                }
            }
            break;
        
        default:
            break;
        }
    }
    
}