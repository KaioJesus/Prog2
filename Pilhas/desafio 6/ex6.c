#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int bool;

typedef struct
{
  int numero;
  char naipe;
} tCarta;

typedef struct aux
{
  tCarta carta;
  struct aux *prox;
} ELEMENTO;

typedef ELEMENTO *PONT;

typedef struct
{
  PONT topo;
} PILHA;

void inicializarPilha(PILHA *p)
{
  p->topo = NULL;
}

bool estaVazia(PILHA *p)
{
  return (p->topo == NULL);
}

bool inserirElemPilha(PILHA *p, tCarta carta)
{
  PONT novo = (PONT)malloc(sizeof(ELEMENTO));
  if (novo == NULL)
    return false;
  novo->carta = carta;
  novo->prox = p->topo;
  p->topo = novo;
  return true;
}

bool excluirElemPilha(PILHA *p, tCarta *carta)
{
  if (p->topo == NULL)
    return false;
  *carta = p->topo->carta;
  PONT apagar = p->topo;
  p->topo = p->topo->prox;
  free(apagar);
  return true;
}

void reinicializarPilha(PILHA *p)
{
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

// ========== FUNÇÃO AUXILIAR FORNECIDA ==========
void exibeCarta(tCarta carta)
{
  if (carta.numero >= 2 && carta.numero <= 10)
    printf("%d", carta.numero);
  else
  {
    switch (carta.numero)
    {
    case 11:
      printf("Valete");
      break;
    case 12:
      printf("Dama");
      break;
    case 13:
      printf("Rei");
      break;
    case 1:
      printf("As");
      break;
    default: // 14
      printf("Invalida");
    }
  }
  printf(" de ");
  switch (carta.naipe)
  {
  case 'o':
    printf("Ouros\n");
    break;
  case 'c':
    printf("Copas\n");
    break;
  case 'p':
    printf("Paus\n");
    break;
  case 'e':
    printf("Espadas\n");
    break;
  }
}

void empilhaBaralho(PILHA *p)
{
  char naipes[] = {'o', 'c', 'p', 'e'};
  tCarta carta;

  for (int i = 0; i < 4; i++)
  {

    for (int j = 1; j <= 13; j++)
    {
      carta.numero = j;
      carta.naipe = naipes[i];
      inserirElemPilha(p, carta);
    }
  }
}

int buscaCarta(PILHA *p, tCarta cartaBuscada)
{
  PILHA pilhaAux;
  inicializarPilha(&pilhaAux);

  tCarta cartaRetirada;
  int cartasRetiradas = 0;
  bool encontrou = false;

  printf("Procurando pela carta: ");
  exibeCarta(cartaBuscada);

  while (!estaVazia(p) && !encontrou)
  {
    excluirElemPilha(p, &cartaRetirada);
    cartasRetiradas++;

    printf("Carta %d retirada: ", cartasRetiradas);
    exibeCarta(cartaRetirada);

    if (cartasIguais(cartaRetirada, cartaBuscada))
    {
      encontrou = true;
      printf("*** CARTA ENCONTRADA! ***\n");
      inserirElemPilha(p, cartaRetirada);
    }
    else
    {
      inserirElemPilha(&pilhaAux, cartaRetirada);
    }
  }

  while (!estaVazia(&pilhaAux))
  {
    excluirElemPilha(&pilhaAux, &cartaRetirada);
    inserirElemPilha(p, cartaRetirada);
  }

  if (encontrou)
  {
    printf("Resultado: Carta encontrada apos retirar %d carta(s)\n\n", cartasRetiradas);
    return cartasRetiradas;
  }
  else
  {
    printf("Resultado: Carta nao encontrada no baralho\n\n");
    return -1;
  }
}

int main()
{
  PILHA baralho;
  inicializarPilha(&baralho);

  empilhaBaralho(&baralho);

  tCarta carta;

  printf("Digite o numero da carta (1-13) e o naipe Digite o naipe (c=Copas, o=Ouros, p=Paus, e=Espadas): ");
  scanf("%d %c", &carta.numero, &carta.naipe);

  if (carta.numero < 1 || carta.numero > 13)
  {
    printf("Numero invalido! Use valores de 1 a 13.\n\n");
    return 0;
  }

  if (carta.naipe != 'c' && carta.naipe != 'o' &&
      carta.naipe != 'p' && carta.naipe != 'e')
  {
    printf("Naipe invalido! Use: c, o, p ou e.\n\n");
    return 0;
  }

  printf("\n");
  int resultado = buscaCarta(&baralho, carta);

  if (resultado > 0)
  {
    exibeCarta(carta);
    printf("%d \n\n", resultado);
  }

  printf("\n");

  reinicializarPilha(&baralho);

  printf("Programa encerrado!\n");
  return 0;
}
