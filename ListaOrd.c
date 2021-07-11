#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main()
{
	int opcao;
	do{
		printf("1 - Criar a lista\n");
		printf("2 - Inserir no Ordenado\n");
		printf("4 - Remover elementos especifico da lista\n");
		printf("5 - Buscar valor especifico\n");
		printf("6 - Remover a lista toda\n");
		printf("7 - Imprimir a lista toda\n");
		printf("0 - Sair\n");
		scanf("%i",&opcao);

		switch(opcao){
			case 1: LISTA *L1 = NULL;
			printf("Lista criada com sucesso\n");
		}
	}while(opcao !=0 );
}
