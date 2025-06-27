#include <stdio.h>

#define true 1;
#define false 0;
typedef int bool;
typedef int StackType;
#define MAX_SIZE 100
typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct
{
    REGISTRO items[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s);
void showStack(Stack *s, int binario[]);

int main()
{
    int numeroAserDividido;
    int *binario;

    printf("Digite um número inteiro positivo para ser convertido em binário: ");
    scanf("%d", &numeroAserDividido);
    if (numeroAserDividido < 0)
    {
        printf("Número inválido. Por favor, insira um número inteiro positivo.\n");
        return 1;
    }
    Stack pilha;
    initStack(&pilha);
    REGISTRO reg;
    int numero = numeroAserDividido;
    printf("\nProcesso de divisão:\n");
    while (numero > 0)
    {
        int resto = numero % 2; // Resto da divisão por 2
        printf("%d ÷ 2 = %d, resto = %d\n", numero, numero / 2, resto);
        // Empilha o resto
        reg.chave = resto;
        if (!push(&pilha, reg))
        {
            printf("Erro ao empilhar o valor %d.\n", resto);
            return 1;
        }
        numero = numero / 2; // Divisão inteira por 2
    }
    // Desempilha os restos para formar o número binário
    printf("\nDesempilhando os restos (leitura de baixo para cima):\n");
    printf("Binário: ");
    while (stackSize(&pilha) > 0)
    {
        if (!pop(&pilha))
        {
            printf("Erro ao desempilhar.\n");
            return 1;
        }
        showStack(&pilha, &binario);
    }
    printf("\n\n");
    for (int i = 0; i < stackSize(&pilha); i++)
    {
        printf("%d", binario[i]);
    }
    return 0;
}

void initStack(Stack *s)
{
    // inicializa a pilha, definindo o topo como -1 (indicando que a pilha está vazia)
    s->top = -1;
}

int stackSize(Stack *s)
{
    return s->top + 1; // o tamanho da pilha é o topo + 1, pois o topo começa em -1 quando a pilha está vazia
}

void showStack(Stack *s, int binario[])
{
    // verifica se a pilha está vazia (caso a pilha esteja vazia, o tamanho é 0, o topo é -1, pois o último elemento do array é o tamanho -1)
    if (s->top == -1)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contents:\n");
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d ", s->items[i].chave);
        binario[i] = s->items[i].chave; // Armazena o valor do registro no array binario
    }
    printf("\n");
}

bool push(Stack *s, REGISTRO reg)
{
    // se a pilha estiver cheia, não é possível inserir um novo elemento
    if (s->top >= MAX_SIZE - 1)
    {
        printf("Stack overflow.\n");
        return false
    }

    // incrementa o topo da pilha e insere o novo elemento
    s->top++;
    s->items[s->top] = reg;
    return true;
}

bool pop(Stack *s)
{
    // se a pilha estiver vazia, não é possível remover um elemento
    if (s->top == -1)
    {
        printf("Stack underflow.\n");
        return false;
    }

    // decrementa o topo da pilha, removendo o elemento do topo
    s->top--;
    return true;
}
