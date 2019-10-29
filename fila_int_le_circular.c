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

int enfileira_fila(int x){
	celula *novo = malloc(sizeof(celula));
	if(novo == NULL) return 0;
	novo->prox = fila->prox;
	fila->prox = novo;
	fila->dado = x;
	fila = novo; 
return 1;
}


int desenfileira_fila(int *x){
	if(fila->prox == fila) return 0;
	celula * lixo = fila->prox;
	*x = lixo->dado;
	fila->prox = lixo ->prox;
	free(lixo);
return 1;
}

int destroi_fila(){
	int elem;
	while(desenfileira_fila(&elem));
	free(fila);
	return 1;
}

int fila_cheia(){
	return 0;
}

int fila_vazia(){

	if(fila == NULL) return 1;
	return 0;
}

int tamanho_fila(){
	int count = 0;

	celula * temp = fila->prox;

	while (temp != fila)

	{
		count++;
		temp = temp->prox;
	}
	return count;
}

int imprime_fila(){

	celula * temp = fila->prox;
	int posicao = 2;

	for(int i = 0; i < 6*tamanho_fila(); i++) printf("-"); //linha superior
    puts("");
	while(temp != fila) {
		printf("| %03d ", temp->dado); //conteudo
		temp = temp->prox;
	}
    puts("|"); 
	for(int i = 0; i < 6*tamanho_fila(); i++) printf("-"); //linha inferior
    puts("");

	printf("  p");
	temp = fila->prox;
	
	for (int i = 0; i < 6*tamanho_fila(); i++)
	{
		printf(" ");
	}puts("u");
}	

