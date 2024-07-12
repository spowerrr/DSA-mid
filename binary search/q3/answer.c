#include <stdio.h>

int findPeakElement(int nums[], int n) {
  int low = 0;
  int high = n - 1;

  if (low == 0 && nums[low] >= nums[low + 1]) {
    printf("Peak element is: %d\n", nums[low]);
  }
  if (high == n - 1 && nums[high] >= nums[high - 1]) {
    printf("Peak element is: %d\n", nums[high]);
  }

  while (low < high) {
    int mid = (low + high) / 2;

    /// Check if mid is a peak element....

    if ((mid == 0 || nums[mid] >= nums[mid - 1]) &&
        (mid == n - 1 || nums[mid] >= nums[mid + 1])) {
      return mid;
    }

    /// If the element to the right of mid is greater, then peak element must be
    /// in the right half....

    if (mid < n - 1 && nums[mid] < nums[mid + 1]) {
      low = mid + 1;
    }
    /// Otherwise, peak element must be in the left half....

    else {
      high = mid - 1;
    }
  }

  /// low == high is the peak element index when the loop terminates

  if (low == 0 || low == n - 1) {
    return 0;
  } else {
    return low;
  }
}

int main(void) {
  int nums[] = {8, 9, 10, 2, 5, 6};
  int n = sizeof(nums) / sizeof(nums[0]);

  int peakIndex = findPeakElement(nums, n);
  printf("Peak element is: %d\n", nums[peakIndex]);

  return 0;
}
