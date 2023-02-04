#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void print_array(int* array, int len) {
    for (int i=0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int maximum(int array[], int len) {
    int max = INT_MIN;
    for (int i=0; i < len; i++) {
        if (max < array[i]) {
            max = array[i];
        }
    }
    return max;
}

void count_sort(int array[], int len) {
    int i, j;
    int max = maximum(array, len);
    int *count = (int*) malloc((max+1) * sizeof(int));
    for (i=0; i < max+1; i++) {
        count[i] = 0;
    }

    for (i=0; i < len; i++) {
        count[array[i]] += 1;
    }

    i = j = 0;

    while (i <= max) {
        if (count[i] > 0) {
            array[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else {
            i++;
        }
    } // while

    free(count);
}

int main(void) {
    int A[] = {3, 1, 9, 7, 1, 2, 4};
    int length = sizeof(A) / sizeof(A[0]);
    print_array(A, length);
    count_sort(A, length);
    print_array(A, length);
}
