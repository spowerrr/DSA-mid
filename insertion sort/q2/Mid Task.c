#include <stdio.h>

void insertionSort(int arr[], int n, int *comparisons, int *shifts) {
    *comparisons = 0;
    *shifts = 0;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            (*comparisons)++;
            arr[j + 1] = arr[j];
            j--;
            (*shifts)++;
        }

        // Place the key after the element just smaller than it.
        arr[j + 1] = key;
        (*shifts)++; // Count the final placement of key

        if (j >= 0) {
            (*comparisons)++; // For the last comparison when arr[j] <= key
        }
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int comparisons, shifts;

    insertionSort(arr, n, &comparisons, &shifts);

    printf("Sorted list: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nComparisons: %d\nShifts: %d\n", comparisons, shifts);

    return 0;
}
