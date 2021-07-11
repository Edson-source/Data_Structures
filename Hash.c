// FUNC�O HASH UTILIZADA: SuaFuncaoAqui
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 50

typedef struct elemento{
  char Aluno;
	int chave;
	struct elemento *next;
}elemento;

typedef struct tabela{
	struct elemento **dados;
}tabela;


tabela* Cria_Tabela(){
	tabela *t = (tabela*) malloc(sizeof(tabela));
	t->dados = (struct elemento**) malloc(tam * sizeof(struct elemento*));
	for(int i=0; i<tam;i++)
		t->dados[i] = NULL;
	return t;
}

void Inserir(tabela *T, int chave, char Name){
	int pos = chave%tam;
	elemento *novo = (elemento*) malloc(sizeof(elemento));

  novo->Aluno = Name;
	novo->chave = chave;
	novo->next = NULL;

	if(T->dados[pos] != NULL)
	{
		elemento *p;
		p = T->dados[pos];
		while(p->next != NULL)
		{
			p = p->next;
		}
		p->next = novo;
	}
	else
		T->dados[pos] = novo;
}

void Busca_Hash(tabela *T, int chave){
  int pos = chave%tam;

    if (T->dados[pos] == NULL) {
      printf("Aluno %d NAO encontrado\n", chave);
    }
    else{
      printf("Aluno %d encontrado na posicao %d\n", chave, pos);
    }
}

int menu(){
	int opcao;
	printf("\n1 - Inserir Aluno\n");
	printf("2 - Buscar Aluno por matricula\n");
	printf("0 - Sair\n");
	scanf("%i",&opcao);
	return(opcao);
}

int main(){
	int opcao, Matricula;
  char Name[50];

  elemento *T = (elemento*)malloc(tam*sizeof(elemento));

  Cria_Tabela();

	do{
		opcao = menu();

		switch(opcao){
			case 1: printf("Digite o nome do aluno\n");
              scanf("%s", &Name);
              printf("Digite a matricula do aluno\n");
              scanf("%d", &Matricula);
              Inserir(T, Matricula, Name);
                    break;
			case 2: printf("Digite a matricula para fazer a busca\n");
              scanf("%d", &Matricula);
              Busca_Hash(T, Matricula);
					break;
			case 0: exit(1);
    	}
	}while(opcao !=0);
}
