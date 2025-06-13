#include <stdio.h>
#include <stdlib.h>

void buscaSeqOrdRep(int arr[], int tam, int el, int *pos, int *quant)
{
  *pos = -1; // Inicializa posição como não encontrado
  *quant = 0;
  for (int i = 0; i < tam; i++)
  {
    if (arr[i] == el)
    {
      printf("%d %d \n", arr[i], el);
      if (*pos == -1)
      {
        *pos = i;
      }
      (*quant)++;
    }

    else if (arr[i] > el)
    {
      break;
    }
  }
}

int main()
{
  int quantidade, el, pos, tam;
  printf("Digite o tamnho do vetor: ");
  scanf("%d", &tam);
  int *arr = (int *)malloc(tam * sizeof(int));

  if (arr == NULL)
  {
    printf("Erro: memória insuficiente.\n");
    return 1;
  }

  printf("Digite os elementos do Vetor: \n");
  for (int i = 0; i < tam; i++)
  {
    scanf("%d", &arr[i]);
  }

  printf("Digite o elemento procurado: \n");
  scanf("%d", &el);

  buscaSeqOrdRep(arr, tam, el, &pos, &quantidade);

  printf("posição da primeira ocorrência: %d", pos);
  printf("Quantidade de ocorrências: %d", quantidade);

  return 0;
}
