# Repositório de Exercícios de Estrutura de Dados

Esse repositório destina-se aos estudos, documentação e implementação dos conteúdos de Estrutura de Dados.

## Mantenedores

| Nome | E-mail |
| --- | --- |
| Letícia Meneses | lmbs.geo@gmail.com |

## 1. Módulo 1

### 1.1. Algorítmo de Fila Circular

#### 1.1.1. Header
Esse algorítmo utiliza uma fila composta por inteiros, contendo um arquivo `flat_int_circular.h` como header do programa implementado, contendo a declaração das seguintes funções:

* ***inicializa_fila*** ;
* ***enfileira_fila*** ;
* ***desenfileira_fila*** ;
* ***destroi_fila*** ;
* ***fila_cheia*** ;
* ***fila_vazia*** ;
* ***tamanho_fila*** ;
* ***imprime_fila*** .

#### 1.1.2. Código

O Código implementado no arquivo `flat_int_circular.c` utiliza alocação dinâmica para dimensionamento da fila, utilizando para armazenamento dessa estrutura um vetor de número de elementos predefinido, adicionando e removendo elementos inteiros pela abordagem de ponteiros

### 1.2. Algorítmo de Fila Circular com Lista Encadeada

#### 1.2.1. Header
Esse programa possui uma declaração similar à contida no tópico **1.1.1**, com as mesmas estuturas de retorno nas funções, porém sem a passagem de parâmetros.

#### 1.2.2. Código

O Código implementado no arquivo `flat_int_le_circular.c`, por sua vez, utiliza um tipo abstrato de dados como struct para armazenar as células que farão parte da fila cirular de inteiros formada, tomando o seguinte formado:

```
typedef struct celula{
	int dado;
	struct celula *prox;
}celula;
```

Assim, as funções implementadas utilizam essa estrutura para inserir elementos que possam ser acessados, utilizando a alocação dinâmica para cada célula inserida e não para todo um vetor alocado, permitindo maior facilidade na remoção e adiço de valores, sem perdas de referências ou 'shifts' a esquerda para elementos na fila no caso da retirada de um elemento. 





