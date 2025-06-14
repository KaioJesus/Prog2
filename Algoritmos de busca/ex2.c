#include <stdio.h>
#include <stdlib.h>

void buscaMenorMaiorBin(int arr[], int tam, int el, int *menor, int *maior)
{
  int fim = tam - 1;
  int ini = 0;
  *menor = 0;
  *maior = 0;
  while (ini <= fim)
  {
    int meio = (fim + ini) / 2;
    if (arr[meio] < el)
    {
      ini = meio + 1;
    }
    else
    {
      fim = meio - 1;
      if (arr[meio] == el)
        *maior = *maior - 1;
    }
  }
  *menor = ini;
  *maior = *maior + (tam - ini);
}

int main()
{
  int el, tam, menor, maior;

  scanf("%d", &tam);
  scanf("%d", &el);

  int *arr = (int *)malloc(tam * sizeof(int));

  if (arr == NULL)
  {
    return 1;
  }

  for (int i = 0; i < tam; i++)
  {
    scanf("%d", &arr[i]);
  }

  buscaMenorMaiorBin(arr, tam, el, &menor, &maior);

  printf("Menor: %d - Maior: %d", menor, maior);
  free(arr);
  return 0;
}
