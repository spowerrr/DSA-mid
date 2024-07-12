#include <stdio.h>

void selectionSort(int arr[], int n, int order) {
    int i, j, idx, temp;

    for (i = 0; i < n-1; i++) {
        idx = i;
        for (j = i+1; j < n; j++) {
            if ((order == 1 && arr[j] < arr[idx]) ||
                (order == 2 && arr[j] > arr[idx])) {
                idx = j;
            }
        }
        if (idx != i) {
            temp = arr[idx];
            arr[idx] = arr[i];
            arr[i] = temp;
        }
    }
}

int main() {
    int n, i,order;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("1. Ascending\n2. Descending \nEnter your choice: ");
    scanf("%d", &order);

    selectionSort(arr, n, order);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
