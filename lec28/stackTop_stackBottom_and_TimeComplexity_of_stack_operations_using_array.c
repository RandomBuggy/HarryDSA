#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int size;
    int top;
    int* array;
} Stack;

// function prototype
int isFull(Stack*);
int isEmpty(Stack*);
void push(Stack*, int);
int pop(Stack*);
int peek(Stack*, int);
int stackTop(Stack*);
int stackBottom(Stack*);

// time complexity
// isEmpty() -- O(1)
// isFull() -- O(1)
// push() -- O(1)
// pop() -- O(1)
// peek() -- O(1)
// stackTop() -- O(1)
// stackBottom() -- O(1)


int main(void) {
    Stack* sp = (Stack*) malloc(sizeof(Stack));
    sp -> size = 10;
    sp -> top = -1;
    sp -> array = (int*) malloc(sp -> size * sizeof(int));

    for (int i = 15; i <= 25; i++) {
        push(sp, i);
    }

    /* for (int i = 0; i <= 11; i++) {
        continue;
        printf("%d is popped from the stack\n", pop(sp));
    }
    for (int i = 1; i <= 10; i++) {
        printf("Peek Value %d of position %d\n", peek(sp, i), i);
        } */
    printf("stackTop Value: %d\n", stackTop(sp));
    printf("stackBottom Value: %d\n", stackBottom(sp));
    return 0;
}

int isFull(Stack* ptr) {
    return (ptr -> top == ptr -> size - 1) ? 1 : 0;
}

int isEmpty(Stack* ptr) {
    return ptr -> top == -1 ? 1 : 0;
}

void push(Stack* ptr, int value) {
    if (isFull(ptr)) {
        printf("Stack Overflow\nCan not push %d to the stack\n", value);
    }
    ptr -> top++;
    ptr -> array[ptr -> top] = value;
}

int pop(Stack* ptr) {
    if (isEmpty(ptr)) {
        printf("Stack Underflow\nCan not pop from the stack\n");
        return -1;
    }
    int temp = ptr -> array[ptr -> top];
    ptr -> top--;
    return temp;
}

int peek(Stack* ptr, int position) {
    int index = ptr -> top - position + 1;
    if (index < 0 || index > ptr -> top) {
        printf("Invalid Position\n");
        return -1;
    }
    else {
        return ptr -> array[index];
    }
}

int stackTop(Stack* ptr) {
    return ptr -> array[ptr -> top];
}

int stackBottom(Stack* ptr) {
    return ptr -> array[0];
}
