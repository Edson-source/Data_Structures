#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

int main(int argc, char const *argv[]) {
  int v[10], va[10], n, aux, i, j, k=0;

// Vetor com quantos numeros o usuario quiser
  printf("Digite quantos numeros tera o vetor\n");
  scanf("%d", &n);

//Leitura do vetor
  printf("Digite %d numeros\n", n);
  for (i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }

//Ordenação Crescente
  for (i = 1; i < n; i++) {
    for (j = 0; j < n-1; j++) {
      if (v[j]>v[j+1]) {
        aux = v[j];
        v[j]= v[j+1];
        v[j+1] = aux;
      }
    }
  }

printf("\n\n");

//Imprime Vetor Ordenado
for (i = 0; i < n; i++) {
  printf("%d ", v[i]);
}

printf("\n\n");

//Remoção dos numeros repetidos
  for (i = 0; i < n; i++) {
    for (j = i+1; j <= n; j++) {
        if (v[j]==v[i]) {
          break;
        }
        else{
          va[k]=v[i];
          k++;
        }
        break;
    }
}

//Imprime Vetor sem repetição
for (i = 0; i < k; i++) {
  printf("%d ", va[i]);
}

  return 0;
}
