#include <stdio.h>

void selection_sort_optimized(int arr[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            // Even pass
            for (j = 0; j < n - 1; j += 2) {
                     printf("even: \n");
                if (arr[j] > arr[j + 1]) {
                        printf("element a[j] %d , a[j+1] %d\n",arr[j],arr[j+1]);
                    // Swap arr[j] and arr[j + 1]
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;

                     printf("Sorted array: ");
                     print_array(arr, n);

                }
            }
        } else {
            // Odd pass
            for (j = 1; j < n - 1; j += 2) {
                    printf("odd: \n");
                if (arr[j] > arr[j + 1]) {
                        printf("element a[j] %d , a[j+1] %d\n",arr[j],arr[j+1]);
                    // Swap arr[j] and arr[j + 1]
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    printf("element %d \n",arr[j]);
                     printf("Sorted array: ");
                     print_array(arr, n);

                }
            }
        }
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11,24,26,28};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    print_array(arr, n);

    selection_sort_optimized(arr, n);

    printf("Sorted array: ");
    print_array(arr, n);

    return 0;
}
