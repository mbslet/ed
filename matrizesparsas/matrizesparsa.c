#include<stdio.h>

typedef struct no{
    int coluna;
    int valor;
    struct no *prox;
} no;

typedef struct matriz{
    int linhas;
    int colunas;
    no ** valores;
}matriz;

void inicializa(int linhas, int colunas, matriz *m){
    m->linhas = linhas;
    m->colunas = colunas;
    m->valores = malloc(linhas * sizeof(no*));
    for(int i=0; i<linhas; i++){
        m->valores[i] = malloc(sizeof(no));
        m->valores[i]->prox = NULL;
    }
}

void inserir(int linha, int coluna, int valor, matriz *m){
    no *anterior = m->valores[linha];
    no *atual = anterior->prox;

    while(atual != NULL && atual->coluna<coluna){
        anterior = atual;
        atual = atual ->prox;
    }
     if(atual == NULL || atual -> coluna > coluna){
         if(valor!=0){                                     
             no *novo = malloc(sizeof(no));
             novo -> coluna = coluna;
             novo -> prox = atual;
             anterior -> prox = novo;
         }
     }
    else{                                                   
        if(valor != 0)
            atual->valor = valor;
        else{
            anterior->prox=atual->prox;
            free(atual);
        }
     }
    }
   
   int multiplica(int linha, matriz *m, int vetor[linha]){
       int *vet = malloc(sizeof(int));

       for(int k = 0; k<linha; k++){
           vet = m->linhas
       }
   }

int main(){

    int linha, coluna;
    int posl, posc, valor;
    matriz *mat;
    mat = malloc(sizeof(matriz));

    scanf("Insira o numero de linhas: %d", &linha);
    scanf("Insira o numero de colunas: %d", &coluna);

    int vetor[linha];
    for(int i=0; i<linha; i++){
        scanf("%d", &vetor[i]);
    }

    inicializa(linha, coluna, mat);

    
    while(scanf("%d %d %d", &posl, &posc, &valor)!= EOF){
        inserir(posl, posc, valor, mat);

    }
    
}