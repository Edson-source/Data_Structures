#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define false 0;
#define true 1;

typedef struct Arvore{
  int num;
  struct Arvore *esquerda;
  struct Arvore *direita;
}No;

void Cria_Arvore(No** Raiz){
  *Raiz = NULL;
}

int Verifica_Vazio(No* Raiz){
  if (Raiz == NULL) {
    return 1;
  }
  else{
    return 0;
  }
}

void Inserir_Arvore(No** Raiz, int x){

  if (Verifica_Vazio(*Raiz)==1){

        (*Raiz) = (No*) malloc(sizeof(No));
        (*Raiz)->num = x;
        (*Raiz)->esquerda = NULL;
	      (*Raiz)->direita = NULL;
	}

	else{
		if (x < (*Raiz)->num){
			Inserir_Arvore(&(*Raiz)->esquerda, x);
		}
		if (x > (*Raiz)->num){
			Inserir_Arvore(&(*Raiz)->direita, x);
		}
	}
}

void Remover_Arvore(No* Raiz, int x){
No* aux = Raiz;

if(Raiz == NULL){
     printf("Numero nao existe na arvore!");
     getch();
  }
  if(x < Raiz->num)
        Remover_Arvore(Raiz->esquerda, x);
  else if(x > Raiz->num)
        Remover_Arvore(Raiz->direita, x);
     else{    // if (x == Raiz->num)
        if ((Raiz->esquerda == NULL) && (Raiz->direita == NULL)){         // se nao tem filhos
              free(aux);
              Raiz = NULL;
              printf("Elemento %d Removido\n", x);
             }
        else{                 // so tem o filho da direita
           if (Raiz->esquerda == NULL){
              Raiz = Raiz->direita;
              aux->direita = NULL;
              free(aux);
              aux = NULL;
              printf("Elemento %d Removido\n", x);
              }
           else{            //so tem o filho da esquerda
              if (Raiz->direita == NULL){
                  Raiz = Raiz->esquerda;
                  aux->esquerda = NULL;
                  free(aux);
                  aux = NULL;
                  printf("Elemento %d Removido\n", x);
              }
              else{
                 aux = Raiz->direita; //tem 2 filhos e o maior vai substituir
                 aux->esquerda = Raiz->esquerda;
                 aux->direita = Raiz->direita;
                 Raiz->esquerda = Raiz->direita = NULL;
                 free(Raiz);
                 Raiz = aux;
                 aux = NULL;
                 printf("Elemento %d Removido\n", x);
              }
           }
        }
     }
}

void Buscar_Elem(No* Raiz, int x){

  if (Verifica_Vazio(Raiz)) {
    printf("Arvore Vazia\n");
  }

  else if (Raiz->num==x) {
    printf("Elemento %d encontrado\n", x);
  }
  else{
    Buscar_Elem(Raiz->esquerda, x);
    Buscar_Elem(Raiz->direita, x);
  }
}

void Mostrar_Ordem(No* Raiz){
  if(Raiz != NULL){
      Mostrar_Ordem(Raiz->esquerda);
      printf("%d ", Raiz->num);
      Mostrar_Ordem(Raiz->direita);
  }
  else{
    printf("- ");
  }
}

void Mostrar_Pos(No* Raiz){
  if(Raiz != NULL){
      Mostrar_Pos(Raiz->esquerda);
      Mostrar_Pos(Raiz->direita);
      printf("%d ", Raiz->num);
  }
  else{
    printf("- ");
  }
}

void Mostrar_Pre(No* Raiz){

  if(Raiz != NULL){
      printf("%d ", Raiz->num);
      Mostrar_Pre(Raiz->esquerda);
      Mostrar_Pre(Raiz->direita);
  }
  else{
    printf("- ");
  }
}

void Desalocar(No* Raiz){
  free(Raiz);
  printf("\nArvore Desalocada\n");
}

int Desafio(No* Raiz){
int i=1, j=1;

  if (Raiz != NULL) {
    printf("(");
    printf("%d", Raiz->num);
    i = Desafio(Raiz->esquerda);
    j = Desafio(Raiz->direita);
    if (i == NULL && j == NULL) {
      printf("()");
    }
    else if(j == NULL && i != NULL || j != NULL && i != NULL){
      printf(")");
    }
  }
}

int main(){

  No *NO= (No*) malloc(sizeof(No));
  int opcao, x;

	do{
    printf("\n------------------------------------------------------\n");
    printf("1 - Criar a arvore                                      \n");
    printf("2 - Inserir                                             \n");
    printf("3 - Remover                                             \n");
    printf("4 - Buscar elemento                                     \n");
    printf("5 - Mostrar Em Ordem                                    \n");
    printf("6 - Mostrar Pos Ordem                                   \n");
    printf("7 - Mostrar Pre-Ordem                                   \n");
    printf("8 - Desalocar                                           \n");
    printf("9 - Desafio >> Mostrar arvore em formato de arvore      \n");
    printf("0 - Sair                                                \n");
    printf("------------------------------------------------------  \n");
    scanf("%i",&opcao);

		switch(opcao){
			case 1:
          system("cls");
          Cria_Arvore(&NO);
          printf("Arvore criada com sucesso\n");
					break;
			case 2:
          system("cls");
          printf("Elemento a ser inserido: ");
					scanf("%d", &x);
          Inserir_Arvore(&NO, x);
          break;

			case 3:
          system("cls");
          printf("Elemento a ser removido: ");
					scanf("%d",&x);
          Remover_Arvore(NO, x);
					break;
			case 4:
          system("cls");
          printf("Elemento a ser buscado: ");
					scanf("%d",&x);
          Buscar_Elem(NO, x);
					break;
      case 5:
          printf("Mostrar Ordem\n");
          Mostrar_Ordem(NO);
          break;
      case 6:
          printf("Mostrar Pos-Ordem\n");
          Mostrar_Pos(NO);
          break;
      case 7:
          printf("Mostrar Pre-Ordem\n");
          Mostrar_Pre(NO);
          break;
      case 8:
          Desalocar(NO);
          break;
      case 9:
          Desafio(NO);
          break;
			}
	}while(opcao !=0);
}
