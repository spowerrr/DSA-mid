#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n)
{
    int j;
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void findMostOccurence(int arr[], int n, int *mostOcc, int *maxcount)
{
    int currentcount = 1;
    *mostOcc = arr[0];
    *maxcount = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            currentcount++;
        }
        else
        {
            if (currentcount > *maxcount)
            {
                *maxcount = currentcount;
                *mostOcc = arr[i - 1];
            }
            currentcount = 1;
        }
    }
    if (currentcount > *maxcount)
    {
        *maxcount = currentcount;
        *mostOcc = arr[n - 1];
    }
}

int main()
{
    int arr[] = {43, 31, 50, 31, 26, 29, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxcount;
    int mostOcc;

    insertionSort(arr, n);

    printf("Sorted list: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    findMostOccurence(arr, n, &mostOcc, &maxcount);
    printf("The most occurrence in the array is: %d", mostOcc);
    printf("\n");
    printf("%d times", maxcount);
    return 0;
}