#include <stdio.h>
#include <stdlib.h>
int binarySearch(int arr[], int n, int target) {
  int low = 0;
  int high = n - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] < target) {
      low = mid + 1;
    } else if (arr[mid] > target) {
      high = mid - 1;
    } else {
      return mid;
    }
  }

  return low;
}

void findNClosestElements(int arr[], int target, int N, int n) {
  int i = binarySearch(arr, n, target);

  int left = i - 1;
  int right = i;

  while (N-- > 0) {
    if (left < 0 ||
        (right < n && abs(arr[left] - target) > abs(arr[right] - target))) {
      right++;
    } else {
      left--;
    }
  }
  left++;
  while (left < right) {
    printf("%d ", arr[left]);
    left++;
  }
}

int main() {
  int n, N, target;
  scanf("%d %d %d", &n, &N, &target);
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  findNClosestElements(arr, target, N, n);

  return 0;
}
