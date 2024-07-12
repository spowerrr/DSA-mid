#include <stdio.h>

// Function to find the target in a rotated sorted array
int find_in_rotated_array(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the target element to search: ");
    scanf("%d", &target);

    int result = find_in_rotated_array(arr, n, target);
    if (result != -1)
    {
        printf("Element found at index: %d\n", result);
    }
    else
    {
        printf("Element not found\n");
    }

    return 0;
}

// in binary search
#include <stdio.h>

int find_in_rotated_array(int arr[], int n, int target)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            // Check for the first occurrence of the target
            while (mid > 0 && arr[mid - 1] == target)
            {
                mid--;
            }
            return mid;
        }

        // If the left half is sorted
        if (arr[low] <= arr[mid])
        {
            if (target >= arr[low] && target < arr[mid])
            {
                high = mid - 1; // Target is in the left half
            }
            else
            {
                low = mid + 1; // Target is in the right half
            }
        }
        // If the right half is sorted
        else
        {
            if (target > arr[mid] && target <= arr[high])
            {
                low = mid + 1; // Target is in the right half
            }
            else
            {
                high = mid - 1; // Target is in the left half
            }
        }
    }

    return -1; // Target not found
}

int main()
{
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 0;

    int result = find_in_rotated_array(arr, n, target);

    if (result != -1)
    {
        printf("Target %d found at index %d\n", target, result);
    }
    else
    {
        printf("Target %d not found in the array\n", target);
    }

    return 0;
}
