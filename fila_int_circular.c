#include<stdlib.h>
#include<stdio.h>

static int *fila;
static int p, u, n = 6;
//Fila circular com redimensionamento.


//1. Criação da fila
//Deve inicializar as estruturas necessárias a fila e os indicadores.
int inicializa_fila(){
    p = 0;
    u = 0;
    fila = malloc(n * sizeof(int));
    if (fila == NULL) return 0;
    return 1;
}
//2. Inserção na fila
//Deve inserir um novo elemento na fila, retornando 1 se o elemento foi inserido com sucesso, 0 caso contrário.
int enfileira_fila(int x){
    int fila_cheia();
    int redimensiona_fila();
    fila[u++] = x;
    if (fila_cheia()){ //se estiver cheia dobra o tamanho da fila
        redimensiona_fila();
        printf("Fila cheia, redimensionamento automático\n");
    }
    return 1;
}
//3. Remoção da fila
//Deve remover um elemento da fila, e retornar 1 caso a remoção tenha sido bem sucedida
//(neste caso, retornando também o elemento removido) ou 0 caso contrário.
int desenfileira_fila(int *x){
    if(p == u) return 0;
    *x = fila[p];
    p = (p + 1) % n;
    return 1;
}

//4. Verificação se a fila está cheia
//Deve retornar 1 se a fila estiver cheia, 0 caso contr´ario.
int fila_cheia(){
    if((u + 1) % n == p) return 1;
    return 0;
}

//5. Verificação se a fila está vazia
//Deve retornar 1 se a fila estiver vazia, 0 caso contr´ario.
int fila_vazia(){
    if (p == u) return 1;
    return 1;
}

//6. Tamanho da fila
//Deve retornar quantos elementos há na fila.
int tamanho_fila(){
    if(p > u) return u - p + n;
    return u - p;
}

//7. Impressão da fila
//Deve imprimir a fila no seguinte formato:
//-----------------------------------------------------------
//| xxx | xxx | xxx | xxx | xxx | xxx | xxx | xxx | xxx | xxx |
//-----------------------------------------------------------
//p                         u
int imprime_fila(){
    int tamanho_fila();
    for(int i = 0; i < 6*tamanho_fila(); i++) printf("-"); //linha superior
    puts("");
    for(int i = 0; i < tamanho_fila(); i++) printf("| %03d ", fila[i]); //conteudo
    puts("|");
    for(int i = 0; i < 6*tamanho_fila(); i++) printf("-"); //linha inferior
    puts("");

//imprimir p e u

    int i, u;
    char pp, uu;

    if(p<=u){
        pp = 'p';
        i = p;
        uu = 'u';
        u = u;
    }else{
        pp = 'u';
        i = u;
        uu = 'p';
        u = p;
    }

    for(int j = 0;j <= u; j++){
        if(j == i){
            printf("   %c", pp);
            for(int k = j; k <= n; k++){
                if(k == u){
                    printf("%c", uu);
                }
                else{
                    printf("      ");
                }
            }
            break;
        }
        else{
            printf("      ");
        }
    }

    printf("\n");
}



}

int redimensiona_fila(){
    int i, j;
    fila = realloc(fila, 2*n*sizeof(int));
        if(u != n - 1){
            if(u-1 < n - p){
                for(i = n, j = 0; j < u; i++, j++)
                    fila[i] = fila[j];
                u = n + u;
            }
            else{
                for(i = p, j = n + p; i < n; i++, j++)
                    fila[j] = fila[i];
                p = n + p;
            }
        }
        n *= 2;
    return 1;
}

int destroi_fila(){
    int aux;
    while(desenfileira_fila(&aux));
    n = 5;
    return 1;
}