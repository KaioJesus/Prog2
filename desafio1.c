#define valor_max 100
#include <stdio.h>
#include <math.h>

int closest_to_mean_index(int *arr, int arrLength)
{
    int sum = 0;
    for (int i = 0; i < arrLength; i++)
    {
        sum += arr[i];
    }

    int media = sum / arrLength;

    int indexClosestNumber = 0;
    int leastDifferenceBetweenMediaAndArr = abs(media - arr[0]);

    for (int j = 0; j < arrLength; j++)
    {
        if (abs(media - arr[j]) < leastDifferenceBetweenMediaAndArr)
        {
            leastDifferenceBetweenMediaAndArr = abs(media - arr[j]);
            indexClosestNumber = j;
        }
    }

    return indexClosestNumber;
}

int main()
{
    int arrLength, arr[valor_max];

    printf("Informe o tamanho do array: \n");
    scanf("%d", &arrLength);

    for (int i = 0; i < arrLength; i++)
    {
        printf("Informe o valor do array na posicao %d: \n", i);
        scanf("%d", &arr[i]);
    }

    int index = closest_to_mean_index(arr, arrLength);
    printf("O indice do valor que contem a menor diferenca absoluta e: %d", index);

    return 0;
}