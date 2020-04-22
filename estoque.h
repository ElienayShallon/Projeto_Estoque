#ifndef ESTOQUE_H_INCLUDED
#define ESTOQUE_H_INCLUDED

#define MAX 100
#define TAM 10
#define LIN 10
#define COL 10

struct Produto{
	int id;
	char nome[MAX];
	float preco;
};
typedef struct Produto TProduto;

void exibe_menu();
void le_produto(TProduto vetor[TAM], int *pn);
void le_abastecimento(int vetor[TAM], int *pn);
void le_estoque(int matriz[LIN][COL], int *plinhas, int *pcolunas);
void imprime_estoque(int matriz[LIN][COL], int *plinhas, int *pcolunas);
void faz_abastecimento(int matriz[LIN][COL], int *plinhas, int *pcolunas, int vetor[TAM]);
int pesquisa_produto(TProduto vetor[TAM], int matriz[LIN][COL], int *plinhas, int *pcolunas);
void gravacao (FILE* file, int* plinhas, int* pcolunas,  int matriz[LIN][COL], int vetor_abastecimento[TAM]);
void leitura (FILE* file, int* plinhas, int* pcolunas, int matriz[LIN][COL], int vetor_abastecimento[TAM]);

#endif // ESTOQUE_H_INCLUDED
