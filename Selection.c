#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int v[10], i, j, eleito, num, menor, pos;

  printf("Digite a quantidade de numeros\n");
  scanf("%d", &num);

  printf("Digite %d numeros\n", num);
  for (i = 0; i < num; i++) {
    scanf("%d", &v[i]);
  }

  for (i = 0; i < num-1; i++) {
    eleito = v[i];
    menor = v[i+1];
    pos = i+1;
    for (j = i+1; j < num; j++) {
      if (v[j] < menor) {
        menor = v[j];
        pos = j;
      }
    }
    if (menor < eleito) {
      v[i] = v[pos];
      v[pos] = eleito;
    }
  }

  for (i = 0; i < num; i++) {
    printf("%d ", v[i]);
  }
  return 0;
}
