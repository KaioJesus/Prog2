#include <stdio.h>

#define true 1;
#define false 0;
typedef int bool;
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
void showStack(Stack *s);

int main()
{
    return 0;
}

void initStack(Stack *s)
{
    s->top = -1;
}

void showStack(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contents:\n");
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d ", s->items[i].chave);
    }
    printf("\n");
}

bool push(Stack *s, REGISTRO reg)
{
    if (s->top >= MAX_SIZE - 1)
    {
        printf("Stack overflow.\n");
        return false
    }

    s->top++;
    s->items[s->top] = reg;
    return true;
}

bool pop(Stack *s, REGISTRO *reg)
{
    if (s->top == -1)
    {
        printf("Stack underflow.\n");
        return false;
    }
    *reg = s->items[s->top];
    s->top--;
    return true;
}
