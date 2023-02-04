#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int data;
    struct stack* next;
} Stack;

// prototype
int isEmpty(Stack*);
int isFull(Stack*);
Stack* push(Stack*, int);
int pop(Stack**);
int peek(Stack*, int);
int stackTop(Stack*);
void LinkedListTraversal(Stack*);

int main() {
    Stack* top = NULL;
    top = push(top, 12);
    top = push(top, 22);
    top = push(top, 32);
    top = push(top, 42);
    LinkedListTraversal(top);
    printf("popped value %d\n", pop(&top));
    LinkedListTraversal(top);
    printf("Peeked value %d\n", peek(top, 2));
    LinkedListTraversal(top);
    printf("Stack top value : %d\n", stackTop(top));
    return 0;
}

int isEmpty(Stack* top) {
    return top == NULL ? 1 : 0;
}

int isFull(Stack* top) {
    Stack* ptr = (Stack*) malloc(sizeof(Stack));
    return ptr == NULL ? 1 : 0;
}

Stack* push(Stack* top, int value) {
    if (isFull(top)) {
        printf("Stack Overflow.\n");
    }
    Stack* tmp_ptr = (Stack*) malloc(sizeof(Stack));
    tmp_ptr -> data = value;
    tmp_ptr -> next = top;
    top = tmp_ptr;
    return top;
}

int pop(Stack** top) {
    if (isEmpty(*top)) {
        printf("Stack Underflow\n");
    }
    Stack* tmp_ptr = *top;
    *top = (*top) -> next;
    int value = tmp_ptr -> data;
    free(tmp_ptr);
    return value;
}

void LinkedListTraversal(Stack* ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr -> data);
        ptr = ptr -> next;
    }
}

int peek(Stack* top, int position) {
    Stack* tmp_ptr = top;
    for (int i = 0; (i < position - 1 && tmp_ptr != NULL); i++) {
        tmp_ptr = tmp_ptr -> next;
    }
    if(tmp_ptr != NULL) {
        int data = tmp_ptr -> data;
        free(tmp_ptr);
        return data;
    }
    return -1;
}

int stackTop(Stack* top) {
    return top -> data;
}
