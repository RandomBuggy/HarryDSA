/* recursive merge sort */
#include <stdio.h>


void print_array(int* array, int len) {
    for (int i=0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void merge(int array[], int low, int mid, int high) {
    int b[high+1];
    int i, j, k;
    i = k = low;
    j = mid + 1;

    while (i <= mid && j <= high) {
        if (array[i] < array[j]) {
            b[k] = array[i];
            k++; i++;
        }
        else {
            b[k] = array[j];
            k++; j++;
        }
    }
    while (i <= mid) {
        b[k] = array[i];
        i++; k++;
    }
    while (j <= high) {
        b[k] = array[j];
        j++; k++;
    }

    for (int i=low; i <= high; i++) {
        array[i] = b[i];
    }
}

void merge_sort(int array[], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        merge_sort(array, low, mid);
        merge_sort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}

int main(void) {
    int a[] = {2, 4, 3, 9, 1, 4, 8, 7, 5, 6};
    int length = sizeof(a) / sizeof(a[0]);
    print_array(a, length);
    merge_sort(a, 0, length - 1);
    print_array(a, length);
}
