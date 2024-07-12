#include <stdio.h>

// Function to swap two integers by their indices in an array
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function to perform selection sort in ascending order for even numbers
void selectionSortEven(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n-1; i++) {
        if (arr[i] % 2 == 0) {
            min_idx = i;
            for (j = i+1; j < n; j++) {
                if (arr[j] % 2 == 0 && arr[j] < arr[min_idx]) {
                    min_idx = j;
                }
            }
            swap(arr, min_idx, i);
        }
    }
}

// Function to perform selection sort in descending order for odd numbers
void selectionSortOdd(int arr[], int n) {
    int i, j, max_idx;

    for (i = 0; i < n-1; i++) {
        if (arr[i] % 2 != 0) {
            max_idx = i;
            for (j = i+1; j < n; j++) {
                if (arr[j] % 2 != 0 && arr[j] > arr[max_idx]) {
                    max_idx = j;
                }
            }
            swap(arr, max_idx, i);
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11, 90, 55, 33};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    selectionSortEven(arr, n);
    selectionSortOdd(arr, n);

    printf("Sorted array with even numbers in ascending order and odd numbers in descending order: \n");
    printArray(arr, n);

    return 0;
}
