#include <stdio.h>
#define MAX 100

int main() {
  int n, i, v[MAX];

  printf("digite o comprimento da sequência: ");
  scanf("%d", &n);

  printf("digite uma sequência com %d números inteiros: ", n);
  for (i = 0; i < n; i++)
    scanf("%d", &v[i]);
  for (i = n-1; i >= 0; i--)
    printf("%d ", v[i]);
  printf("\n");
  return 0;
}