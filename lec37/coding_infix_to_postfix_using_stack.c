#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
    int size;
    int top;
    char* array;
} Stack;

// function prototype
int isFull(Stack*);
int isEmpty(Stack*);
void push(Stack*, char);
char pop(Stack*);
int stackTop(Stack*);
int stackBottom(Stack*);
int isOperator(char);
int precedense(char);
char* infix_to_postfix(char*);

int main(void) {
    int size;
    printf("Enter expression size : ");
    scanf("%d", &size);
    char* infix = (char*) malloc(size * sizeof(char));
    printf("Enter a infix expression : ");
    scanf("%s", infix);
    char* postfix = infix_to_postfix(infix);
    printf("Equivalent postfix : %s\n", postfix);
    free(infix);
    free(postfix);
    return 0;
}

int isFull(Stack* ptr) {
    return (ptr -> top == ptr -> size - 1) ? 1 : 0;
}

int isEmpty(Stack* ptr) {
    return ptr -> top == -1 ? 1 : 0;
}

void push(Stack* ptr, char value) {
    if (isFull(ptr)) {
        printf("Stack Overflow\nCan not push %d to the stack\n", value);
    }
    ptr -> top++;
    ptr -> array[ptr -> top] = value;
}

char pop(Stack* ptr) {
    if (isEmpty(ptr)) {
        printf("Stack Underflow\nCan not pop from the stack\n");
        return -1;
    }
    char temp = ptr -> array[ptr -> top];
    ptr -> top--;
    return temp;
}

int stackTop(Stack* ptr) {
    return ptr -> array[ptr -> top];
}

int stackBottom(Stack* ptr) {
    return ptr -> array[0];
}

int precedense(char ch) {
    if (ch == '*' || ch == '/') {
        return 2;
    }
    else if (ch == '+' || ch == '-') {
        return 1;
    }
    else {
        return 0;
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/') ? 1 : 0;
}

char* infix_to_postfix(char* infix) {
    int i = 0/* track infix traversal */, j = 0 /* track postfix appending */;
    char* postfix = (char*) malloc((strlen(infix) + 1) * sizeof(char));
    Stack* sp = (Stack*) malloc(sizeof(Stack));
    sp -> size = 100;
    sp -> top = -1;
    sp -> array = (char*) malloc(sp -> size * sizeof(char));

    while (infix[i] != '\0') {
        if(!isOperator(infix[i])) {
            postfix[j] = infix[i];
            i++; j++;
        }
        else {
            if (precedense(infix[i]) > precedense(stackTop(sp))) {
                push(sp, infix[i]);
                i++;
            }
            else {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }

    while(!isEmpty(sp)) {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    free(sp);
    return postfix;
}
