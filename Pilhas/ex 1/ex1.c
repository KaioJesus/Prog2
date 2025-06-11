#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;
typedef struct
{
  TIPOCHAVE chave;
} REGISTRO; // Define um registro que armazena dados (neste caso, apenas uma chave inteira)

typedef struct aux
{
  REGISTRO reg;
  struct aux *prox;
} ELEMENTO; // Define um nó da pilha contendo um registro e um ponteiro para o próximo elemento

typedef ELEMENTO *PONT;

typedef struct{
  PONT topo;
} PILHA; // Define a estrutura da pilha, que mantém apenas um ponteiro para o topo

void inicializarPilha(PILHA *p)
{
  p->topo = NULL;
} // Define o topo como NULL (pilha vazia)

int tamanho(PILHA *p)
{
  PONT end = p->topo;
  int tam = 0;
  while (end != NULL)
  {
    tam++;
    end = end->prox;
  }
  return tam;
}
bool estaVazia(PILHA *p)
{
  if (p->topo == NULL)
    return true;
  return false;
}

void exibirPilha(PILHA *p)
{
  PONT end = p->topo;
  printf("Pilha: \" ");
  while (end != NULL)
  {
    printf("%i ", end->reg.chave);
    end = end->prox;
  }
  printf("\"\n");
}

// Insere no topo (operação PUSH)
// Aloca memória para novo elemento
// Coloca o novo elemento no topo
// Atualiza o ponteiro topo
bool inserirElemPilha(PILHA *p, REGISTRO reg)
{
  PONT novo = (PONT)malloc(sizeof(ELEMENTO));
  if (novo == NULL)
    return false;
  novo->reg = reg;
  novo->prox = p->topo;
  p->topo = novo;
  return true;
}

// Remove do topo (operação POP)
// Retorna o elemento removido por referência
// Libera a memória do elemento removido
bool excluirElemPilha(PILHA *p, REGISTRO *reg)
{
  if (p->topo == NULL)
    return false;
  *reg = p->topo->reg;
  PONT apagar = p->topo;
  p->topo = p->topo->prox;
  free(apagar);
  return true;
}


void reinicializarPilha(PILHA *p){
  PONT apagar;
  PONT posicao = p->topo;
  while (posicao != NULL)
  {
    apagar = posicao;
    posicao = posicao->prox;
    free(apagar);
  }
  p->topo = NULL;
}

// FUNÇÃO PARA CONVERSÃO DECIMAL PARA BINÁRIO
void decimalParaBinario(int numeroDecimal)
{
  PILHA pilha;
  inicializarPilha(&pilha);

  printf("Convertendo %d para binário:\n", numeroDecimal);

  // Caso especial: número zero
  if (numeroDecimal == 0)
  {
    printf("Binário: 0\n");
    return;
  }

  // Processo de conversão usando divisões sucessivas por 2
  int numero = numeroDecimal;
  printf("\nProcesso de divisão:\n");

  while (numero > 0)
  {
    int resto = numero % 2; // Resto da divisão por 2
    printf("%d ÷ 2 = %d, resto = %d\n", numero, numero / 2, resto);

    // Empilha o resto
    REGISTRO reg;
    reg.chave = resto;
    inserirElemPilha(&pilha, reg);

    numero = numero / 2; // Divisão inteira por 2
  }

  // Desempilha os restos para formar o número binário
  printf("\nDesempilhando os restos (leitura de baixo para cima):\n");
  printf("Binário: ");

  REGISTRO reg;
  while (!estaVazia(&pilha))
  {
    excluirElemPilha(&pilha, &reg);
    printf("%d", reg.chave);
  }
  printf("\n\n");

  // Limpa a pilha
  reinicializarPilha(&pilha);
}

// PROGRAMA PRINCIPAL PARA TESTAR
int main()
{
  int numero;
  char continuar;

  printf("=== CONVERSOR DECIMAL PARA BINÁRIO ===\n\n");

  do
  {
    printf("Digite um número decimal positivo: ");
    scanf("%d", &numero);

    if (numero < 0)
    {
      printf("Por favor, digite apenas números positivos!\n\n");
      continue;
    }

    decimalParaBinario(numero);

    printf("Deseja converter outro número? (s/n): ");
    scanf(" %c", &continuar);
    printf("\n");

  } while (continuar == 's' || continuar == 'S');

  printf("Programa encerrado!\n");
  return 0;
}
