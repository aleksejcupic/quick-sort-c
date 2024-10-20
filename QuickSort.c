// C implementation of QuickSort
#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

/* This function makes the last element the pivot,
and places all smaller elements to the left and larger to
the right. */
int partiton(int arr[], int low, int high){
    int pivot = arr[high]; // pivot
    int i = (low -1); // index of smaller element

    for (int j = low; j <= high - 1; j++){
        // If current element is smaller than pivot
        if (arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Main sorting function
void quickSort(int arr[], int low, int high){
    if (low < high){
        // "pi" is partioning index
        int pi = partiton(arr, low, high);

        // Separately sort elements before and after partition
        quickSort(arr, low, pi -1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size){
    int i;
    for (i = 0; i < size; i++)
        printf("%d\n", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    printArray(arr, n);
    
    return 0;
}