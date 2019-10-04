#include <stdio.h>
#include <stdlib.h>

void random_shuffle(int vector[], int size)
{
    srand(time(NULL));
    int i, j, temp;
    for (i = size - 1; i > 0; i--)
    {
        j = rand()%(i + 1);
        temp = vector[i];
        vector[i] = vector[j];
        vector[j] = temp;
    }
}

void swapQS(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partion(int vector[], int start, int end)
{
    int pivotIndex = start + rand()%(end - start + 1);
    int pivot;
    int i = start - 1;
    int j;

    pivot = vector[pivotIndex];
    swapQS(&vector[pivotIndex], &vector[end]);

    for (j = start; j < end; j++)
    {
        if (vector[j] < pivot)
        {
            i++;
            swapQS(&vector[i], &vector[j]);
        }
    }

    swapQS(&vector[i+1], &vector[end]);
    return i + 1;
}

void quick_sort(int vector[], int start, int end)
{
    int j;

    if (start < end)
    {
        j = partion(vector, start, end);
        quick_sort(vector, start, j-1);
        quick_sort(vector, j+1, end);
    }
}
