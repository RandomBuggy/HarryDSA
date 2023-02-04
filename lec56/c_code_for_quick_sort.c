#include <stdio.h>


void print_array(int *array, int len) {
    for (int i=0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int partition(int *array, int low, int high) {
    int temp;
    int pivot = array[low];
    int i = low + 1;
    int j = high;

    do {
        while (array[i] <= pivot) {i++;}

        while (array[j] > pivot) {j--;}

        if (i < j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    } while(i < j);
    // swap array[low] and array[j]
    temp = array[low];
    array[low] = array[j];
    array[j] = temp;
    return j;
}

void quick_sort(int *array, int low, int high) {
    int partition_index; // index of pivot

    if (low < high) {
        partition_index = partition(array, low, high);
        quick_sort(array, low, partition_index - 1); // sort left sub-array
        quick_sort(array, partition_index + 1, high); // sort right sub-array
    }
}

int main(void) {
    int a[] = {2, 4, 3, 9, 1, 4, 8, 7, 5, 6};
    int length = sizeof(a) / sizeof(a[0]);
    print_array(a, length);
    quick_sort(a, 0, length - 1);
    print_array(a, length);
}
