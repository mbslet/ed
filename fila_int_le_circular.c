#include<stdio.h>
#include<stdlib.h>

typedef struct celula{
	int dado;
	struct celula *prox;
}celula;

celula *fila;

int inicializa_fila(){
	fila = malloc(sizeof(celula));
	if(fila==NULL) return 0;
	fila->prox = fila;
return 1;
}

int enfileira(int x){
	celula *novo = malloc(sizeof(celula));
	if(novo == NULL) return 0;
	novo->prox = fila->prox;
	fila->prox = novo;
	fila->dado = x;
	fila = novo; 
return 1;
}


int desenfileira(int *x){
	if(fila->prox == fila) return 0;
	celula * lixo = fila->prox;
	*x = lixo->dado;
	fila->prox = lixo ->prox;
	free(lixo);
return 1;
}

int destroi_fila(){
	int elem;
	while(desenfileira(&elem));
	free(fila);
	return 1;
}

int fila_cheia(){
	
}
