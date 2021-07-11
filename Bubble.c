#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

int main(int argc, char const *argv[]) {
  int v[10], n, aux, i, j;

  printf("Digite quantos numeros tera o vetor\n");
  scanf("%d", &n);

  printf("Digite %d numeros\n", n);
  for (i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }

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

  for (i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }
  return 0;
}
