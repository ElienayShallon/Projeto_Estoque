#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estoque.h"

void exibe_menu(){
	printf("\nGerenciamento de estoque\n");
	printf("1 - Abastecer estoque\n");
	printf("2 - Pesquisar produto\n");
	printf("3 - Sair\n");
}

// Para saber o nome do produto e o seu preço
 void le_produto(TProduto vetor[TAM], int *pn){
	int i;

	printf("\nInforme os produtos:\n");

	for (i = 0; i < *pn; i++){

		printf("\nNome: ");
		fgets(vetor[i].nome, MAX-1, stdin);

		printf("Preco: ");
		scanf("%f", &vetor[i].preco);

		getchar();
		vetor[i].id = i;
	}

}

// Para Pesquisar o produto especifico
int pesquisa_produto(TProduto vetor[TAM], int matriz[LIN][COL], int *plinhas, int *pcolunas) {

	char nome[MAX];
	int j; /* indexador de produtos */
	int i; /* indexador de lojas */
	int id = -1;

	printf("\nEntre com o nome do produto: ");
	fgets(nome, MAX-1, stdin);

	for (j = 0; j < *pcolunas; j++) {

		if (strcmp(vetor[j].nome, nome) == 0) {

			printf("\nID: %d\n", vetor[j].id);
			printf("Nome: %s", vetor[j].nome);
			printf("Preco: %.2f\n\n", vetor[j].preco);

			id = vetor[j].id;
			for (i = 0; i < *plinhas; i++) {
				printf("Loja %d: %d unidades\n", i, matriz[i][id]);
 			}
		}
	}

	if (id >= 0) {
		return 1;
	}

	return 0;
}

// Para imformar a quantidade de unidades cada produto tem.
void le_estoque(int matriz[LIN][COL], int *plinhas, int *pcolunas) {

	int i, j;

 	printf("\nInforme o numero de unidades que tem no estoque:\n");

 	for (i=0; i<*plinhas; i++) {
 	 	for (j=0; j<*pcolunas; j++) {
 		 	scanf("%d", &matriz[i][j]);
 	 	}
 	 	printf("\n");
 	}
}

void imprime_estoque(int matriz[LIN][COL], int *plinhas, int *pcolunas) {

	int i, j;

	printf("\nEstoque atualizado:\n");

 	for (i=0; i<*plinhas; i++) {
 	 	for (j=0; j<*pcolunas; j++) {
 		 	printf("%d ", matriz[i][j]);
 	 	}
 	 	printf("\n");
 	}
}

// Para saber a quantidade de abastecimento a ser se feito
void le_abastecimento(int vetor[TAM], int *pn) {

	int i;

 	printf("\nInforme para abastecer em quantos:\n");

 	for (i=0; i<*pn; i++) {
		scanf("%d", &vetor[i]);
 	}
 	printf("\n");
}
// para fazer o abastacimento de acordo com a quantidade de designada
void faz_abastecimento(int matriz[LIN][COL], int *plinhas, int *pcolunas, int vetor[TAM]) {

	int i, j, pos_menor;

 	for (i=0; i<*plinhas; i++) {

		pos_menor = 0;
		for (j=0; j<*pcolunas; j++) {

			if (matriz[i][j] < matriz[i][pos_menor]) {
				pos_menor = j;
			}
		}

		matriz[i][pos_menor] += vetor[pos_menor];
 	}
}

// Para criar Um Arquivo com os dados
void gravacao (FILE* file, int* plinhas, int* pcolunas, int matriz[LIN][COL], int vetor_abastecimento[TAM]){
	int i,j;

	printf("---------------------------------\n");
	printf("Gravando\n");
	printf("---------------------------------\n");

	fwrite(plinhas, sizeof(int), 1, file);
	printf("Dados de loja gravados\n");
	printf("---------------------------------\n");

	fwrite(pcolunas, sizeof(int), 1, file);
	printf("Dados de produtos gravados\n");
	printf("---------------------------------\n");

	fwrite(matriz, sizeof(int), (*plinhas) * (*pcolunas), file);
 	printf("Estoque Gravado\n");
	printf("---------------------------------\n");

	fwrite(vetor_abastecimento, sizeof(int), *pcolunas, file);
	printf("Abastecimento Gravado\n");
	printf("---------------------------------\n");
}

// Para fazer a leitura do Arquivo Criado
// Não funciona direito (ainda...)
void leitura (FILE* file, int* plinhas, int* pcolunas, int matriz[LIN][COL], int vetor_abastecimento[TAM]){

	printf("\n _Abrindo_ \n");

	fread(plinhas, sizeof(int), 1, file);
	printf("%i\n", *plinhas);

	fread(pcolunas, sizeof(int), 1, file);
	printf("%i\n", *pcolunas);

	fread(matriz, sizeof(int), (*plinhas) * (*pcolunas), file);
	printf("%i\n",matriz[LIN][COL]);

	fread(vetor_abastecimento, sizeof(int), *pcolunas, file);
	printf("%i\n",vetor_abastecimento[TAM]);
}

