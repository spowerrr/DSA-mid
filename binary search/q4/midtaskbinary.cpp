#include <iostream>
using namespace std;
int returnRotation(int a[], int n) {
  int mid, low, high, next, prev;
  low = 0;
  high = n - 1;
  while (low <= high) {
    if (a[low] < a[high])
      return low; // It's not rotated
    else {
      mid = low + (high - low) / 2;
      next = (mid + 1) % n;
      prev = (mid - 1 + n) % n;
      if (a[mid] < a[next] && a[mid] < a[prev])
        return mid;
      else if (a[low] > a[mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
  }
  return 0;
}
int main() {
  int arr[] = {4, 5, 6, 1, 2, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << returnRotation(arr, n);
}
