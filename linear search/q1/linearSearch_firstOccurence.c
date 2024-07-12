#include <stdio.h>

// Function to perform linear search for the first occurrence
int linear_search_first(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1; // Target not found
}

int main()
{
    int size;

    // Prompt the user to enter the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Ensure the size is positive
    if (size <= 0)
    {
        printf("The size of the array must be positive.\n");
        return 1;
    }

    int arr[size];

    // Prompt the user to enter each element of the array
    printf("Enter %d elements of the array:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int target;
    // Prompt the user to enter the target value
    printf("Enter the target value to search for: ");
    scanf("%d", &target);

    int index = linear_search_first(arr, size, target);

    // Print the index of the first occurrence found or indicate if not found
    if (index != -1)
    {
        printf("Target %d found at index %d\n", target, index);
    }
    else
    {
        printf("Target %d is not present in the array.\n", target);
    }

    return 0;
}
