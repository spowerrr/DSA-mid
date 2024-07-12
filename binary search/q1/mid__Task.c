#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2; // Prevents overflow

        if (arr[mid] == target)
        {
            return mid; // Target found
        }
        else if (arr[mid] < target)
        {
            left = mid + 1; // Search in the right half
        }
        else
        {
            right = mid - 1; // Search in the left half
        }
    }

    // If target is not found, left is the insertion position
    return left;
}

// Function to print the result
void printResult(int arr[], int n, int target)
{
    int result = binarySearch(arr, n, target);
    if (result < n && arr[result] == target)
    {
        printf("Element %d found at index %d.\n", target, result);
    }
    else
    {
        printf("Element %d not found. It can be inserted at index %d.\n", target, result);
    }
}

int main()
{
    int arr[] = {1, 3, 5, 6, 8, 10, 12, 15, 18};

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The array:\n ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int targets[] = {5, 7, 18, 2, 20}; // Example target values
    int numTargets = sizeof(targets) / sizeof(targets[0]);

    for (int i = 0; i < numTargets; i++)
    {
        printResult(arr, n, targets[i]);
    }

    return 0;
}
