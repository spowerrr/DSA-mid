#include <stdio.h>

int linear_search(int arr[], int size, int target) {
    int occurrences = 0;
    printf("Indices of occurrences of %d in the array: ", target);

    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            printf("%d ", i);
            occurrences++;
        }
    }
    printf("\n");

    return occurrences;
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Error: Array size should be positive.\n");
        return 1;
    }

    int arr[size];
    printf("Enter %d elements of the array:\n", size);
    for (int i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the target value to search for: ");
    scanf("%d", &target);

    int occurrences = linear_search(arr, size, target);

    if (occurrences > 0) {
        printf("Total occurrences of %d in the array: %d\n", target, occurrences);
    } else {
        printf("Target %d is not present in the array.\n", target);
    }

    return 0;
}
