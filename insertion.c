#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int v[10], i, j, eleito, num;

  printf("Digite quantos numeros tera o vetor\n");
  scanf("%d", &num);

  printf("Digite %d numeros\n", num);
  for (i = 0; i < num; i++) {
    scanf("%d", &v[i]);
  }

  for (i = 1; i < num; i++) {
    eleito = v[i];
    j = i-1;
    while (j >= 0 && v[j] > eleito) {
      v[j+1]= v[j];
      j= j-1;
    }
    v[j+1] = eleito;
  }

  for (i = 0; i < num; i++) {
    printf("%d ", v[i]);
  }
  return 0;
}
