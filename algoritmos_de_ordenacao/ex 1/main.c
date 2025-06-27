#include <stdio.h>

//  Funções de ordenação
//  Essas funções ordenam um array de inteiros em ordem decrescente (inverted order).
//  Elas são implementadas usando os algoritmos de ordenação: Bubble Sort, Insertion Sort e Selection Sort.

// Bubble Sort -> ordenada pelo valor do elemento atual comparado com o próximo elemento
// Insertion Sort -> ordenada pelo valor do elemento atual comparado com os elementos anteriores
// Selection Sort -> ordenada pelo valor do elemento atual comparado com o menor elemento restante
void bubbleSortInverted(int *arr, int size);
void insertionSortInverted(int *arr, int size);
void selectionSortInverted(int *arr, int size);

int main()
{
    int arr[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    selectionSortInverted(arr, size);

    printf("Array ordenado: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void bubbleSortInverted(int *arr, int size)
{
    int aux = 0;

    for (int lastElement = size - 1; lastElement > 0; lastElement--)
    {
        for (int i = 0; i < lastElement; i++)
        {
            if (arr[i] < arr[i + 1])
            {
                aux = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = aux;
            }
        }
    }
}

void insertionSortInverted(int *arr, int size)

{
    for (int i = 1; i < size; i++)
    {
        while (arr[i] > arr[i - 1])
        {
            int aux = arr[i - 1];
            arr[i - 1] = arr[i];
            arr[i] = aux;
            i--;
        }
    }
}

void selectionSortInverted(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] > arr[maxIndex])
            {
                maxIndex = j;
            }
        }
        if (maxIndex != i)
        {
            int aux = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = aux;
        }
    }
}