#include <stdio.h>

//traversal 
void display(int a[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

//insertion
int insert(int array[], int element, int index, int size, int capacity) {
    if (size >= capacity) {
        return -1;
    }

    else {
        for (int i = size - 1; i >= index; i--) {
            array[i + 1] = array[i];
        }

        array[index] = element;

        return 1;
    }
}

int main() {
    int size = 7, capacity = 100;
    int array[100] = {877, 635, 427, 173, 856, 361, 648};
    display(array, size);

    size += insert(array, 454, 4, size, capacity);
    display(array, size);
    return 0;
}

