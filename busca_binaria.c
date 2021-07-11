#include <stdio.h>
#include <stdlib.h>

void quick_sort(int a[], int left, int right);

void quick_sort(int a[], int left, int right) {
    int i, j, pivo, y;

    pivo = a[(left + right) / 2];
    i = left;
    j = right;

    while(i <= j) {
        while(a[i] < pivo && i < right) {
            i++;
        }
        while(a[j] > pivo && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}

int main(int argc, char const *argv[]) {
  int i, achou, n, v[10];

  printf("Digite um numero\n");
  scanf("%d", &n);

  printf("Digite um vetor com 10 elementos\n");
  for (i = 0; i < 10; i++) {
    scanf("%d", &v[i]);
  }

  quick_sort(v, 0, 9);

  achou = 0;
  i = 0;

  while (i <= 9 && achou == 0 && n >= v[i]) {
    if (v[i] == n) {
      achou = 1;
      printf("\nNumero %d encontrado na posiçao %d\n", n, i);
    }
    else{
      i++;
    }
    if (i == 9 && v[i] != n) {
      printf("\nNumero %d nao encontrado\n", n);
    }
  }
  return 0;
}
