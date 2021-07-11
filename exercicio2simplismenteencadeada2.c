#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct Lista{
      int            num;
      struct Lista *next;
}elemento;

void inicializa_lista(elemento *no) {
  no->next = NULL;
}

int verifica_vazio(elemento *no) {

  if (no->next ==  NULL) {
    printf("lista vazia\n");
    return 1;
  }

  return 0;
}

void inserir_inicio(elemento *no, int dado){
  elemento *novo = (elemento*)malloc(sizeof(elemento));
  novo->num = dado;
  elemento *head = no;
    novo->next = head;
    no->next = novo;
}

void imprimir_a_lista(elemento *no) {
  elemento *novo = no;
  if (no) {
    do {
      printf(" %d", no->num );
      no = no->next;
    }
    while(no != NULL);
  }
  else
    printf("Lista Vazia\n");
}

int main() {
  elemento* LISTA = (elemento*)malloc(sizeof(elemento));

   inicializa_lista(LISTA);

    int opcao,y,ret,dado;
   do{
 		printf("\n1 - Criar a lista\n");
 		printf("2 - Inserir no inicio\n");
 		printf("3 - Inserir no fim\n");
 		printf("4 - Remover elementos especifico da lista\n");
 		printf("5 - Buscar valor especifico\n");
 		printf("6 - Remover a lista toda\n");
 		printf("7 - Imprimir a lista toda\n");
 		printf("0 - Sair\n");

     printf("insira a escolha:\n");
 		scanf("%i",&opcao);
     system("cls");

 		switch(opcao){
 			case 1:
       inicializa_lista(LISTA);
        printf("iniciou a lista\n");
        getchar();
        verifica_vazio(LISTA);

       break;
       case 2:

       do {
         system("cls");
         printf("digite um numero\n");
         scanf("%d", &dado);
         inserir_inicio(LISTA, dado);
         printf("continuar digite 1\n" );
         scanf("%d", &ret );
       } while(ret != 1);



       ; break;
       case 3: ; break;
       case 4:  ; break;
       case 5:  ; break;
       case 6: ; break;
       case 7:
       system("cls");
       imprimir_a_lista(LISTA);
        break;
       case 0: break;

 			printf("Lista criada com sucesso\n");
 		}
 	}while(opcao != 0 );

  return 0;
}
