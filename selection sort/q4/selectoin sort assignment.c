#include <stdio.h>

// Function to perform selection sort
void selectionSort(int A1[], int N, int A2[], int M) {
    // Traverse through all elements of A2
    for (int i = 0; i < M; ++i) {
        // Find the position of the element A2[i] in A1
        int pos = -1;
        for (int j = 0; j < N; ++j) {
            if (A1[j] == A2[i]) {
                pos = j;
                break;
            }
        }

        // If A2[i] is found in A1, swap A1[i] and A1[pos]
        if (pos != -1 && pos != i) {
            // Swap elements in A1 to maintain order of A2
            int temp = A1[i];
            A1[i] = A1[pos];
            A1[pos] = temp;
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
    int A2[] = {2, 1, 8, 3};
    int N = sizeof(A1) / sizeof(A1[0]);
    int M = sizeof(A2) / sizeof(A2[0]);

    printf("Original A1: ");
    printArray(A1, N);
    printf("A2: ");
    printArray(A2, M);

    // Sort A1 based on the order of A2
    selectionSort(A1, N, A2, M);

    printf("Sorted A1 respecting A2: ");
    printArray(A1, N);

    return 0;
}
