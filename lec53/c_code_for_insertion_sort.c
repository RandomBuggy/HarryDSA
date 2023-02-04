#include <stdio.h>

void print_array(int *a, int len) {
    for (int i=0; i < len; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void insertion_sort(int *a, int len) {
    int j, key;
    for (int i=1; i <= len - 1; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int main(void) {
    int A[] = {12, 54, 65, 23, 7, 9};
    int array_size = sizeof(A) / sizeof(A[0]);
    print_array(A, array_size);
    insertion_sort(A, array_size);
    print_array(A, array_size);
    return 0;
}
