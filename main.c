#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int original[], int quantityOfNumbers);
void validateSort(int copied[], int quantity);

double callInsertionSort(int array[], int quantityOfNumbers);
double callBubbleSort(int array[], int quantityOfNumbers);
double callQuickSort(int array[], int quantityOfNumbers);
double callMergeSort(int array[], int quantityOfNumbers);

int main()
{
    int option = 1, quantityOfNumbers = 0;

    while (option == 1) {
        printf("Digite a quantidade de números a serem ordenados: ");
        scanf("%d", &quantityOfNumbers);

        int original[quantityOfNumbers];
        int upper = quantityOfNumbers + 100;
        int lower = -100;

        int i;
        for (i = 0; i < quantityOfNumbers; i++) {
            original[i] = (rand() % (upper - lower + 1)) + lower;
        }

        sort(original, quantityOfNumbers);
    }

    return 0;
}

void sort(int original[], int quantityOfNumbers) {
    int copied[quantityOfNumbers];
    int loop;

    for(loop = 0; loop < quantityOfNumbers; loop++) {
      copied[loop] = original[loop];
    }

    printf("executing insertion sort...\n");
    double insertionSortExecutionTime = callInsertionSort(copied, quantityOfNumbers);
    validateSort(copied, quantityOfNumbers);
    printf("finished insertion sort: time %fms...\n\n", insertionSortExecutionTime);

    for(loop = 0; loop < quantityOfNumbers; loop++) {
      copied[loop] = original[loop];
    }

    printf("executing bubble sort...\n");
    double bubbleSortExecutionTime = callBubbleSort(copied, quantityOfNumbers);
    validateSort(copied, quantityOfNumbers);
    printf("finished bubble sort: time %fms...\n\n", bubbleSortExecutionTime);

    for(loop = 0; loop < quantityOfNumbers; loop++) {
      copied[loop] = original[loop];
    }

    printf("executing quick sort...\n");
    double quickSortExecutionTime = callQuickSort(copied, quantityOfNumbers);
    validateSort(copied, quantityOfNumbers);
    printf("finished quick sort: time %fms...\n\n", quickSortExecutionTime);

    for(loop = 0; loop < quantityOfNumbers; loop++) {
      copied[loop] = original[loop];
    }

    printf("executing merge sort...\n");
    double mergeSortExecutionTime = callMergeSort(copied, quantityOfNumbers);
    validateSort(copied, quantityOfNumbers);
    printf("finished merge sort: time %fms...\n\n", mergeSortExecutionTime);

    double times[4] = { quickSortExecutionTime, mergeSortExecutionTime, insertionSortExecutionTime, bubbleSortExecutionTime };

    bubbleSortDouble(times, 4);

    printf("\nResultado da ordenação de X números:\n");

    int quickSortAdded = 0, bubbleSortAdded = 0, mergeSortAdded = 0, insertionSortAdded = 0;

    for (loop = 0; loop < 4; loop++) {
        if (times[loop] == quickSortExecutionTime && quickSortAdded == 0) {
            printf("%d - Quick sort     (%.10f ms)\n", loop + 1, quickSortExecutionTime);
            quickSortAdded = 1;
        }
        else if (times[loop] == mergeSortExecutionTime && mergeSortAdded == 0) {
            printf("%d - Merge sort     (%.10f ms)\n", loop + 1, mergeSortExecutionTime);
            mergeSortAdded = 1;
        }
        else if (times[loop] == insertionSortExecutionTime && insertionSortAdded == 0) {
            printf("%d - Insertion sort (%.10f ms)\n", loop + 1, insertionSortExecutionTime);
            insertionSortAdded = 1;
        }
        else if (times[loop] == bubbleSortExecutionTime && bubbleSortAdded == 0) {
            printf("%d - Bubble sort    (%.10f ms)\n", loop + 1, bubbleSortExecutionTime);
            bubbleSortAdded = 1;
        }
    }
    printf("\n");
}


double callInsertionSort(int array[], int quantityOfNumbers) {
	int size = sizeof(array)/sizeof(array[0]);

	clock_t begin = clock();

    insertionSort(array, quantityOfNumbers);

    clock_t end = clock();

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	return time_spent;
}

double callBubbleSort(int array[], int quantityOfNumbers) {
	int size = sizeof(array)/sizeof(array[0]);

	clock_t begin = clock();

	bubbleSort(array, quantityOfNumbers);

    clock_t end = clock();

    double time_spent = ((double)(end - begin) / CLOCKS_PER_SEC) * 1000;
	return time_spent;
}

double callQuickSort(int array[], int quantityOfNumbers) {
    int size = sizeof(array)/sizeof(array[0]);

	clock_t begin = clock();

    quick_sort(array, 0, quantityOfNumbers - 1);

    clock_t end = clock();

    double time_spent = ((double)(end - begin) / CLOCKS_PER_SEC) * 1000;
	return time_spent;
}

double callMergeSort(int array[], int quantityOfNumbers) {
    int size = sizeof(array)/sizeof(array[0]);

	clock_t begin = clock();

    mergeSort(array, 0, quantityOfNumbers - 1);

    clock_t end = clock();

    double time_spent = ((double)(end - begin) / CLOCKS_PER_SEC) * 1000;
	return time_spent;
}

void validateSort(int sorted[], int quantity) {
    int i;
    for(i = 0; i < quantity - 1; i++) {
        if (sorted[i] > sorted [i + 1])
            printf("An error ocurred while sorting!");
    }
}
