#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int size;
    int top;
    int* array;
}Stack;

int isEmpty(Stack*);
int isFull(Stack*);

int main() {
    /* Stack s;
    s.size = 80;
    s.top = -1;
    s.array = (int*) malloc(s.size * sizeof(int));
    */
    Stack *s;
    s = (Stack*) malloc(sizeof(Stack));
    s -> size = 80;
    s -> top = -1;
    s -> array = (int*) malloc(s -> size * sizeof(int));
    //pushing element manually
    //s -> array[0] = 7;
    //s -> top++;

    if (isEmpty(s)) {
        printf("The Stack is Empty\n");
    }
    else {
        printf("The Stack is not Empty\n");
    }
    return 0;
}

int isEmpty(Stack* ptr) {
    if (ptr -> top == -1) {
        return 1;
    }

    else {
        return 0;
    }
}

int isFull(Stack* ptr) {
    if (ptr -> top == ptr -> size - 1) {
        return 1;
    }
    
    else {
        return 0;
    }
}
