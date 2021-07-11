#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha{
    int            topo;
    struct Pilha *pElem;
}Pilha;

void Cria_Pilha(Pilha *p){
    p -> topo = -1;
    p -> pElem = (Pilha*) malloc(sizeof(Pilha));
}

void Push(Pilha *p, int x){
  p -> topo++;
  p -> topo = x;
}

int Pop(Pilha *p){
  Pilha *aux;
  aux = p -> pElem;
  p -> topo--;
  free(aux);
}

void Imprime(Pilha *p){
  int aux;
  aux = p -> topo;
  printf(" %d", aux);
  }

int menu(){
	int opcao;
	printf("1 - Criar a pilha\n");
	printf("2 - Inserir na pilha PUSH\n");
	printf("3 - Remover da pilha POP\n");
	printf("4 - Remover a pilha\n");
	printf("5 - Mostrar a pilha\n");
	printf("0 - Sair\n");
	scanf("%i",&opcao);
	return(opcao);
}

int main()
{
	int opcao, x, num;
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	do{
		opcao = menu();
		switch(opcao){
			case 1:
          Cria_Pilha(p);
          printf("Pilha criada com sucesso\n");
					break;
			case 2:
          printf("Elemento a ser inserido: ");
          scanf("%d",&x);
					Push(p, x);
					break;
			case 3:
          num = Pop(p);
					printf("Elemento removido: %d\n",num);
					break;
			case 4:
					break;
			case 5: Imprime(p);
					break;
			}
	}while(opcao !=0);
}
