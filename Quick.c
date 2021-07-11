#include <stdio.h>
#include <stdlib.h>

#define MAX 10

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

int main(int argc, char** argv){
 int i, a[MAX], b[MAX], c[MAX];

 //Leitura do vetor A e B
 printf("Digite um vetor com 10 elemenos\n");
 for(i = 0; i < MAX; i++){
  scanf("%d", &a[i]);
 }

 printf("Digite mais um vetor com 10 elementos\n");
 for (i = 0; i < MAX; i++) {
   scanf("%d", &b[i]);
 }

 for (i = 0; i < MAX; i++) {
   c[i] = a[i] + b[i];
 }

 printf("A soma dos vetores eh :\n");
 for (i = 0; i < MAX; i++) {
   printf("%d ", c[i]);
 }

 quick_sort(c, 0, MAX - 1);

 printf("\n\nValores ordenados\n");
 for(i = 0; i < MAX; i++){
  printf("%d ", c[i]);
 }

 return 0;
}
