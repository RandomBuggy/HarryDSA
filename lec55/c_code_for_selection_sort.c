#include <stdio.h>

void print_array(int* array, int len) {
    for (int i=0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void selection_sort(int *array, int len) {
    int min_val_index;
    for (int i=0; i < len; i++) {
        min_val_index = i;
        for (int j = i+1;  j < len; j++) {
            if (array[j] < array[min_val_index]) {
                min_val_index = j;
            }
        }
        swap(&array[i], &array[min_val_index]);
    }
}

int main(void) {
    int A[] = {3, 5, 2, 13, 7};
    int len = sizeof(A) / sizeof(A[0]);
    print_array(A, len);
    selection_sort(A, len);
    print_array(A, len);
}
