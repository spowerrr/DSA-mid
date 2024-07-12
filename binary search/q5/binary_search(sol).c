#include <stdio.h>

int binarySearch(int nums[], int n, int target, int searchFirst)
{
    int low = 0, high = n - 1;
    int result = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (target == nums[mid])
        {
            result = mid;
            if (searchFirst)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        else if (target < nums[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return result;
}

int main()
{
    int nums[] = {2, 5, 5, 5, 6, 6, 8, 9, 9, 9};
    int target;
    scanf("%d", &target);

    int n = sizeof(nums) / sizeof(nums[0]);

    int first = binarySearch(nums, n, target, 1);
    int last = binarySearch(nums, n, target, 0);
    int count = last - first + 1;
    if (first != -1)
    {
        printf("Element %d occurs %d times", target, count);
    }
    else
    {
        printf("Element not found in the array");
    }

    return 0;
}