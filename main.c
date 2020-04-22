#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estoque.h"

#define MAX 100
#define TAM 10
#define LIN 10
#define COL 10


int main() {

		TProduto vetor_produto[TAM];
		int matriz_estoque[LIN][COL];
		int vetor_abastecimento[TAM];
		int lojas, produtos;
		int op, id;
		int* pn;
		int* plinhas, *pcolunas;

	pn= &produtos;
	plinhas = &lojas;
	pcolunas = &produtos;

	FILE* grav;
	FILE* ler;
	grav = fopen("C:\\Users\\utilizador\\Documents\\PJestoque\\Gravado_Estoque\\Gravar.bat", "rb");

	if(grav == NULL){
		printf("O arquivo nao foi encontrado\n");
		printf("------------------------------------\n");
		printf("\nEntre com o numero de lojas e produtos:\n");
		do {
			scanf("%d %d", &lojas, &produtos);
		} while (lojas <= 0 || lojas > 10 || produtos <= 0 || produtos > 10);
			getchar();

		le_produto(vetor_produto, &produtos);
		le_estoque(matriz_estoque, &lojas, &produtos);
		le_abastecimento(vetor_abastecimento, &produtos);
	fclose(grav);
	}
	else{
		ler = fopen("C:\\Users\\utilizador\\Documents\\PJestoque\\Gravado_Estoque\\Gravar.bat", "rb");
		leitura(ler, plinhas, pcolunas,  matriz_estoque, vetor_abastecimento);
		fclose(ler);
	}

	do {
		exibe_menu();
		scanf("%d", &op);
		getchar();

		switch (op) {

			case 1:
				faz_abastecimento(matriz_estoque, &lojas, &produtos, vetor_abastecimento);
				imprime_estoque(matriz_estoque, &lojas, &produtos);
				break;

			case 2:
				if (pesquisa_produto(vetor_produto, matriz_estoque, &lojas, &produtos) == 1){
					printf("Operacao realizada com sucesso\n");
				}
				else {
					printf("Produto nao encontrado\n");
				}
				break;

			case 3:
				grav = fopen("C:\\Users\\utilizador\\Documents\\PJestoque\\Gravado_Estoque\\Gravar.bat","wb");
				gravacao (grav, plinhas, pcolunas, matriz_estoque, vetor_abastecimento);
				break;

			default:
				printf("Opcao invalida\n");
				break;
		}

	} while (op != 3);

	return 0;
}
