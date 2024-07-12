#include <stdio.h>

void insertion_sort_numbers(int numbers[], int n) {
    int i, j, key, swaps = 0;
    for (i = 1; i < n; i++) {
        key = numbers[i];
        j = i - 1;
        while (j >= 0 && key < numbers[j]) {
            numbers[j + 1] = numbers[j];
            j--;
            swaps++;
        }
        numbers[j + 1] = key;
    }
    printf("Sorted list: ");
    for (i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    printf("Swaps: %d\n", swaps);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int numbers[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    printf("Original list: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    insertion_sort_numbers(numbers, n);

    return 0;
}
