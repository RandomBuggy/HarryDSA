#include <stdio.h>

//traversal 
void display(int a[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

//insertion
void delete(int array[], int size, int index) {
    /* if (size >= capacity) {
        printf("Element position is out of Size\n");
        return 0;
    } */

    for (int i = index; i < size; i++) {
         array[i] = array[i + 1];
    }
}


int main(void) {
    int array[15] = {7, 9, 56, 33, 76, 23, 78, 47, 52, 78, 32, 90};
    //int size = sizeof(array) / sizeof(int);
    int size = 12;
    display(array, size);
    delete(array, size, 7);
    size -= 1;
    display(array, size);
    return 0;
}

