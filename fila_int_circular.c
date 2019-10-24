#include<stdlib.h>
#include<stdio.h>

static int *fila;
static int p, u, n = 5;

int inicializa_fila(){
    p = 0;
    u = 0;
    fila = malloc(n*sizeof(int));
    if (fila == NULL) return 0;
    return 1;
}
int enfileira_fila(int x){
    if ((u + 1) % n == p) return 0;
    fila[u] = x;
    u = (u + 1) % n;
    return 1;
}
int desenfileira_fila(int *x){
    if(p == u) return 0;
    *x = fila[p];
    p = (p + 1) % n;
    return 1;
}


int fila_cheia(){
    if (((u + 1) % n) == p) return 1;
    return 0;
}
int fila_vazia(){
    if (p == 0 && u == 0) return 1;
    return 0;
}

int redimensiona(){
    int i, j;
    fila = realoc(fila, 2*n*sizeof(int));
    if (p > u){
        if(n-p>u){s\
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
int tamanho_fila(){}
int imprime_fila(){}
int destroi_fila(){}