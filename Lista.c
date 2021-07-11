#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct LISTA{
  int            num;
  struct LISTA *next;
}Lista;

int inicializa_lista(Lista *no){
    no -> next = NULL;
    printf("Lista criada com sucesso\n");

return 0;
}

void verifica_vazio(Lista *no){
  if(no->next == NULL){
    printf("Lista Vazia\n");
  }
  else{
    printf("Não Vazio\n");
  }
}

void inserir_inicio(Lista *no, int dado){
    Lista *novo;
    novo = (Lista*) malloc(sizeof(Lista));

    novo -> num = dado;
    novo -> next = NULL;
    Lista *head = no -> next;
    novo -> next = head;
    no->next= novo;
}

void Inserir_Fim(Lista *no, int dado){
  Lista *novo, *aux;
  novo = (Lista*) malloc(sizeof(Lista));

  novo -> num = dado;
  novo -> next = NULL;

  if (no -> next == NULL) {
    printf("Lista esta vazia\n");
    no -> next = novo;
    novo -> next = NULL;
  }
  else{
    aux = no -> next;
    while (aux -> next != NULL) {
      aux = aux-> next;
    }
    aux->next = novo;
  }
}

void Imprime_Lista(Lista *no){
  Lista *novo;

    if (no -> next == NULL) {
      printf("\n--Fim da Lista--\n");
    }
    else{
      novo = no->next;
      while (no -> next != NULL) {
        printf(" %d", novo->num);
        novo = novo -> next;
      }
      if (no -> next == NULL) {
        printf("\nFim da Lista\n");
      }
    }
}

void Remove_Elem(Lista *no, int dado){
  Lista *aux, *ante;

aux = no -> next;
ante = no -> next;

  while (aux != NULL && aux -> num != dado) {
    ante = aux;
    aux = aux -> next;
  }
  if (aux != NULL) {
    ante->next = aux -> next;
    free(aux);
  }
  printf("Elemento removido com sucesso\n");
}

int Busca_Elem(Lista *no, int dado){
  Lista *novo, *aux;
  novo = (Lista*) malloc(sizeof(Lista));

  novo -> num = dado;
  aux = no -> next;

  while (aux != NULL) {
    if (aux -> num == novo->num) {
      printf("Achou o numero %d\n", novo->num);
      return 0;
    }
    else{
      aux= aux -> next;
    }
  }
  printf("Nao achou o numero %d\n", novo->num);
}

void Remover_Lista(Lista *no){
  free(no);
  printf("Lista desalocada com sucesso\n");
}

int main(){

  Lista *NO= (Lista*) malloc(sizeof(Lista));
	int opcao, dado;

  do{
		printf("\n1 - Criar a lista\n");
		printf("2 - Inserir no inicio\n");
		printf("3 - Inserir no fim\n");
		printf("4 - Remover elementos especifico da lista\n");
		printf("5 - Buscar valor especifico\n");
		printf("6 - Remover a lista toda\n");
		printf("7 - Imprimir a lista toda\n");
		printf("0 - Sair\n");
		scanf("%i",&opcao);

		switch(opcao){

      case 1:
      system("cls");
      inicializa_lista(NO);
      getchar();
			verifica_vazio(NO);
      break;

      case 2:
      system("cls");
      printf("Digite um numero\n");
      scanf("%d", &dado);
      inserir_inicio(NO, dado);
      break;

      case 3:
      system("cls");
      printf("Digite um numero\n");
      scanf("%d", &dado);
      Inserir_Fim(NO, dado);
      break;

      case 4:
      system("cls");
      printf("Digite um numero para remover\n");
      scanf("%d", &dado);
      Remove_Elem(NO, dado);
      break;

      case 5:
      system("cls");
      printf("Digite um numero para buscar na Lista\n");
      scanf("%d", &dado);
      Busca_Elem(NO, dado);
      break;

      case 6:
      system("cls");
      Remover_Lista(NO);
      break;

      case 7:
      Imprime_Lista(NO);
      break;
    }

	}while(opcao !=0 );

return (0);
}
