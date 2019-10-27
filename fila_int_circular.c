#include<stdlib.h>
#include<stdio.h>

static int *fila;
static int p, u, n = 5;
//Fila circular com redimensionamento.


//1. Criação da fila
//Deve inicializar as estruturas necessárias a fila e os indicadores.
int inicializa_fila(){
    p = 0;
    u = 0;
    fila = malloc(n*sizeof(int));
    if (fila == NULL) return 0;
    return 1;
}
//2. Inserção na fila
//Deve inserir um novo elemento na fila, retornando 1 se o elemento foi inserido com sucesso, 0 caso contrário.
int enfileira_fila(int x){
    if ((u + 1) % n == p) return 0;
    fila[u] = x;
    u = (u + 1) % n;
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
    if (((u + 1) % n) == p) return 1;
    return 0;
}

//5. Verificação se a fila está vazia
//Deve retornar 1 se a fila estiver vazia, 0 caso contr´ario.
int fila_vazia(){
    if (p == 0 && u == 0) return 1;
    return 0;
}

//6. Tamanho da fila
//Deve retornar quantos elementos há na fila.
int tamanho_fila(){
    if (fila_vazia()) return 0;
    else if (fila_cheia()) return n;
    else return p;
}

//7. Impressão da fila
//Deve imprimir a fila no seguinte formato:
//-----------------------------------------------------------
//| xxx | xxx | xxx | xxx | xxx | xxx | xxx | xxx | xxx | xxx |
//-----------------------------------------------------------
//p                         u
int imprime_fila(){
    for(int i = 0; i < 6*n; i++) printf("-"); //linha superior
    puts("");
    for(int i = 0; i < n; i++) printf("| %03d | ", fila[i]); //conteudo
    puts("");    
    for(int i = 0; i < 6*n; i++) printf("-"); //linha inferior
    puts("");
}

int redimensiona(){
    int i, j;
    fila = realoc(fila, 2*n*sizeof(int));
    if (p > u){
        if(n-p>u){
            for(i = 0, j = n; i < u; i++, j++)
                fila[j] = fila[i];
            u = n + u;
        }else{
            for (i = n-1, j = 2*n-1; i >= p; i--, j--)
                fila[j] = fila[i];
            p = j + 1;
            n = 2*n;
            return 1;
        }
    }
}

int destroi_fila(){
    int aux;
    while(desenfileira_fila(&aux));
    return 1;
}