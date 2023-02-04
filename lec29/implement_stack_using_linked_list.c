#include <stdio.h>

typedef struct stack {
    int data;
    struct stack* next;
} Stack;

// head node is top -- so push() and pop() from top is O(1) complexity
// stack empty -- top == NULL
// stack full -- heap memory exhausted - node pointer is ptr -> NULL
// you can set a custom size

int main() {

    return 0;
}

