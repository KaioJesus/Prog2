#include <stdio.h>

//  Funções de ordenação
//  Essas funções ordenam um array de inteiros em ordem decrescente (inverted order).
//  Elas são implementadas usando os algoritmos de ordenação: Bubble Sort, Insertion Sort e Selection Sort.

// Bubble Sort -> ordenada pelo valor do elemento atual comparado com o próximo elemento
// Insertion Sort -> ordenada pelo valor do elemento atual comparado com os elementos anteriores
// Selection Sort -> ordenada pelo valor do elemento atual comparado com o menor elemento restante
void bubbleSort(int *arr, int size);
void insertionSort(int *arr, int size);
void selectionSort(int *arr, int size);

int main()
{
    int arr[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    bubbleSortRecursive(arr, size);

    printf("Array ordenado: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void bubbleSortRecursive(int *arr, int size)
{
    int lastElement = size - 1;
    int i = 0;

    sort(arr, lastElement, i);
}

void sort(int *arr, int lastElement, int i)
{
    int aux = 0;
    if (lastElement > 0)
    {
        if (i < lastElement)
        {
            if (arr[i] > arr[i + 1])
            {
                aux = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = aux;
            }
            i++;
            sort(arr, lastElement, i);
        }
        else
        {
            lastElement--;
            i = 0;
        }
        sort(arr, lastElement, i);
    }
}

void insertionSort(int *arr, int size)

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

void selectionSort(int *arr, int size)
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