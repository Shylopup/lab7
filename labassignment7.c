#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int array[], int n, int swaps[]) {
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        arr[i] = array[i];
    }
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                // Increase swaps count for the swapped values
                swaps[0]++;
                swaps[arr[j]]++;
                swaps[arr[j + 1]]++;
            }
        }
    }

    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", arr[i], swaps[arr[i]]);
    }
    printf("total # of swaps: %d\n\n", swaps[0]);

    free(arr);
}

void selectionSort(int array[], int n, int swaps[]) {
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        arr[i] = array[i];
    }
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex == i)
            continue;

        // Swap arr[i] and arr[minIndex]
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

        // Increase swaps count for the swapped values
        swaps[0]++;
        swaps[arr[minIndex]]++;
        swaps[arr[i]]++;  // Increment only for the selected minimum value
    }

    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", arr[i], swaps[arr[i]]);
    }
    printf("total # of swaps: %d\n\n", swaps[0]);

    free(arr);
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);

    int swaps1[100] = {0};  // Assuming values are between 0 and 99
    int swaps2[100] = {0};

    // Bubble Sort for array1
    printf("array 1 bubble sort:\n");
    bubbleSort(array1, n1, swaps1);

    // Bubble Sort for array2
    printf("array 2 bubble sort:\n");
    bubbleSort(array2, n2, swaps2);

    // Reset swaps arrays
    for (int i = 0; i < 100; i++) {
        swaps1[i] = 0;
        swaps2[i] = 0;
    }

    // Selection Sort for array1
    printf("array 1 selection sort:\n");
    selectionSort(array1, n1, swaps1);

    // Selection Sort for array2
    printf("array 2 selection sort:\n");
    selectionSort(array2, n2, swaps2);

    return 0;
}