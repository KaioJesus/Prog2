#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct
{
  TIPOCHAVE chave;
  char nome[50];
  int segundo_chegada;
  int numero_produtos;
  int tempo_saida;
} REGISTRO;

typedef struct aux
{
  REGISTRO reg;
  struct aux *prox;
} ELEMENTO;

typedef ELEMENTO *PONT;

typedef struct
{
  PONT inicio;
  PONT fim;
} FILA;

void inicializarFila(FILA *f)
{
  f->inicio = NULL;
  f->fim = NULL;
}

int tamanho(FILA *f)
{
  PONT end = f->inicio;
  int tam = 0;
  while (end != NULL)
  {
    tam++;
    end = end->prox;
  }
  return tam;
}

void exibirFila(FILA *f)
{
  PONT end = f->inicio;
  printf("Fila: \" ");
  while (end != NULL)
  {
    printf("%s ", end->reg.nome);
    end = end->prox;
  }
  printf("\"\n");
}

bool inserirNaFila(FILA *f, REGISTRO reg)
{
  PONT novo = (PONT)malloc(sizeof(ELEMENTO));
  novo->reg = reg;
  novo->prox = NULL;
  if (f->inicio == NULL)
    f->inicio = novo;
  else
    f->fim->prox = novo;
  f->fim = novo;
  return true;
}

bool excluirDaFila(FILA *f, REGISTRO *reg)
{
  if (f->inicio == NULL)
    return false;
  *reg = f->inicio->reg;
  PONT apagar = f->inicio;
  f->inicio = f->inicio->prox;
  free(apagar);
  if (f->inicio == NULL)
    f->fim = NULL;
  return true;
}

void reinicializarFila(FILA *f)
{
  PONT end = f->inicio;
  while (end != NULL)
  {
    PONT apagar = end;
    end = end->prox;
    free(apagar);
  }
  f->inicio = NULL;
  f->fim = NULL;
}

void simularCaixa()
{
  FILA fila;
  inicializarFila(&fila);

  int K, C;
  printf("Digite K (segundos por produto) e C (número de clientes): ");
  scanf("%d %d", &K, &C);

  for (int i = 0; i < C; i++)
  {
    REGISTRO cliente;
    printf("Digite nome, segundo de chegada e número de produtos: ");
    scanf("%s %d %d", cliente.nome, &cliente.segundo_chegada, &cliente.numero_produtos);
    cliente.chave = i + 1;
    cliente.tempo_saida = 0;
    inserirNaFila(&fila, cliente);
  }

  int tempo_livre_caixa = 0;

  while (fila.inicio != NULL)
  {
    REGISTRO cliente_atual;
    excluirDaFila(&fila, &cliente_atual);

    int inicio_atendimento = (cliente_atual.segundo_chegada > tempo_livre_caixa) ? cliente_atual.segundo_chegada : tempo_livre_caixa;

    int tempo_atendimento = 10 + (cliente_atual.numero_produtos * K);

    cliente_atual.tempo_saida = inicio_atendimento + tempo_atendimento;

    tempo_livre_caixa = cliente_atual.tempo_saida;

    printf("%s %d %d\n", cliente_atual.nome, cliente_atual.segundo_chegada, cliente_atual.tempo_saida);
  }

  reinicializarFila(&fila);
}

int main()
{
  simularCaixa();
  return 0;
}
