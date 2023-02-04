#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 6

void print_array(int *A, int n) {
    for (int i=0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void bubble_sort(int A[], int n) {
    int temp = 0, is_sorted = 0;
    for (int i=0; i < n - 1; i++) { // number of passes
        printf("pass number : %d\n", i + 1); // visualise pass - sorted array
        is_sorted = 1; // for adaptiveness
        for (int j=0;  j < n - 1 - i; j++) { // number of comparison
            if (A[j] > A[j+1]) {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                is_sorted = 0;
            }
        }
        if (is_sorted) break;
    }
}

int main() {
    /* int A[] = {12, 54, 65, 7, 23, 9}; */
    int A[] = {1, 2, 3, 4, 5, 6};

    print_array(A, ARRAY_SIZE);
    bubble_sort(A, ARRAY_SIZE);
    print_array(A, ARRAY_SIZE);
    
    return 0;
}

