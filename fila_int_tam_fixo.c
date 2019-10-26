#include<stdlib.h>
#include<stdio.h>


//Fila de vetor com tamanho fixo

#define n 5
static int fila[n];
static int u, p;

//1. Criação da fila
//Deve inicializar as estruturas necessárias a fila e os indicadores.
int inicializa_fila(){
    p = 0;
    u = 0;
    return 1;
}
//2. Inserção na fila
//Deve inserir um novo elemento na fila, retornando 1 se o elemento foi inserido com sucesso, 0 caso contrário.
int enfileira_fila(int x){
    if(u == n) return 0;
    fila[u] = x;
    u++;
    return 1;
}
//3. Remoção da fila
//Deve remover um elemento da fila, e retornar 1 caso a remoção tenha sido bem sucedida
//(neste caso, retornando também o elemento removido) ou 0 caso contrário.
int desenfileira_fila(int *x){
    if (p == u) return 0;
    *x = fila[p];
    p++;
    return 1;
}

//4. Verificação se a fila está cheia
//Deve retornar 1 se a fila estiver cheia, 0 caso contr´ario.
int fila_cheia(){
    if (u == p) return 1;
    return 0;
}

//5. Verificação se a fila está vazia
//Deve retornar 1 se a fila estiver vazia, 0 caso contr´ario.
int fila_vazia(){
    if (p == 0) return 1;
    return 0;
}

//6. Tamanho da fila
//Deve retornar quantos elementos há na fila.
int tamanho_fila(){
    return u+1;
}

//7. Impressão da fila
//Deve imprimir a fila no seguinte formato:
//-----------------------------------------------------------
//| xxx | xxx | xxx | xxx | xxx | xxx | xxx | xxx | xxx | xxx |
//-----------------------------------------------------------
//   p                       u
int imprime_fila(){
    for(int i = 0; i < n; i++) printf("-");
    puts("");

    for(int i = 0; i < n; i++) printf("| %03d | ", fila[i]);
    puts("");

    for(int i = 0; i < n; i++) printf("-");
    puts("");
}
int destroi_fila(){
    int aux;
    while(desenfileira_fila(aux));
    return 1;
}