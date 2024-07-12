#include <stdio.h>

// Function to find the first occurrence of k
int findFirst(int arr[], int low, int high, int k) {
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if ((mid == 0 || k > arr[mid - 1]) && arr[mid] == k) {
      return mid;
    } else if (k > arr[mid]) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

// Function to find the last occurrence of k
int findLast(int arr[], int low, int high, int k) {
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if ((mid == high || k < arr[mid + 1]) && arr[mid] == k) {
      return mid;
    } else if (k < arr[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return -1;
}

int countOccurrences(int arr[], int n, int k) {
  int first = findFirst(arr, 0, n - 1, k);
  if (first == -1) {
    return 0;
  }

  int last = findLast(arr, 0, n - 1, k);
  return last - first + 1;
}

int main() {
  int arr1[] = {1, 2, 2, 2, 3, 4, 5, 5, 5, 6};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  int k1 = 2;
  printf("Number of occurrences of %d is %d\n", k1,
         countOccurrences(arr1, n1, k1));

  int arr2[] = {1, 2, 2, 2, 3, 4, 5, 5, 5, 6};
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  int k2 = 7;
  printf("Number of occurrences of %d is %d\n", k2,
         countOccurrences(arr2, n2, k2));

  return 0;
}
