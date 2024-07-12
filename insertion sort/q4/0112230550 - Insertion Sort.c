#include <stdio.h>

void insertionSort(int array[], int size) {
    int i, j, key;
    for (i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

double findMean(int array[], int size) {

    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

double findMedian(int array[], int size) {
    if (size % 2 == 0) {
        return (array[size / 2 - 1] + array[size / 2]) / 2.0;
    } else {
        return array[size / 2];
    }
}

int main() {
    int data[] = {12, 13, 13, 22, 24, 10,  13, 15, 15, 16, 16, 18, 25, 23, 24};
    int size = sizeof(data) / sizeof(data[0]);

    insertionSort(data, size);

    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    double mean = findMean(data, size);
    double median = findMedian(data, size);

    printf("Mean: %.2f\n", mean);
    printf("Median: %.2f\n", median);

    return 0;
}
