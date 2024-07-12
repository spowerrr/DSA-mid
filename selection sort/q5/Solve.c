#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void selectionSort(int arr[], int n, char choice)
{
    for (int i = 0; i < n - 1; i++)
    {
        if ((choice == 'E' && arr[i] % 2 != 0) || (choice == 'O' && arr[i] % 2 == 0))
        {
            // Skip elements that are not of the chosen type
            continue;
        }

        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if ((choice == 'E' && arr[j] % 2 == 0 && arr[j] < arr[minIndex]) ||
                    (choice == 'O' && arr[j] % 2 != 0 && arr[j] < arr[minIndex]))
            {
                minIndex = j;
            }
        }

        // Swap only if a valid minimum is found
        if (minIndex != i)
        {
            swap(&arr[i], &arr[minIndex]);
        }
    }
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    char choice;

    printf("Enter choice (E for even, O for odd): ");
    scanf(" %c", &choice);

    // Sort the array based on user choice
    selectionSort(arr, n, choice);

    printf("Output: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

