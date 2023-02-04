#include <stdio.h>
#include <stdlib.h>

struct MyArray {
    int TotalSize;
    int UsedSize;
    int* ptr;
};

void create_array(struct MyArray* array, int tSize, int uSize) {
    array -> TotalSize = tSize;
    array -> UsedSize = uSize;
    array -> ptr = (int*) malloc(tSize * sizeof(int));
}

void show_array(struct MyArray* a) {
    for (int i = 0; i < a -> UsedSize; i++) {
        printf("%d\n", (a -> ptr)[i]);
    }
}

void set_value(struct MyArray* a) {
    int input;
    for (int i = 0; i < a -> UsedSize; i++) {
        printf("Enter element %d : ", i);
        scanf("%d", &input);
        (a -> ptr)[i] = input;
    }
}

int main() {
    struct MyArray marks;
    create_array(&marks, 100, 20);
    set_value(&marks);
    show_array(&marks);
    return 0;
}

