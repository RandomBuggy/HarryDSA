#include <stdio.h>
#include <stdlib.h>

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
int parenthesisMatch(char**);
int match(char, char);


int main(void) {
    char* express = (char*) malloc(20 * sizeof(char));
    printf("Enter a Parenthesis Expression: ");
    scanf("%s", express);
    getchar();
    if (parenthesisMatch(&express)) {
        printf("Parenthesis are balanced\n");
    }
    else {
        printf("Parenthesis are not balanced\n");
    }
    free(express);
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

int match(char a, char b) {
    if (a == '(' && b == ')' || a == '{' && b == '}' || a == '[' && b == ']') {
        return 1;
    }
    return 0;
}

int parenthesisMatch(char** exp) {
    Stack* sp = (Stack*) malloc(sizeof(Stack));
    sp -> size = 8;
    sp -> top = -1;
    sp -> array = (char*) malloc(sp -> size * sizeof(char));
    char popped_char;

    for (int i = 0; (*exp)[i] != '\0'; i++) {
        if ((*exp)[i] == '(' || (*exp)[i] == '{' || (*exp)[i] == '[') {
            push(sp, (*exp)[i]);
        }
        else if ((*exp)[i] == ')' || (*exp)[i] == '}' || (*exp)[i] == ']') {
            if(isEmpty(sp)) {
                return 0;
            }
            popped_char = pop(sp);

            if (!match(popped_char, (*exp)[i])) {
                return 0;
            }
        }
    }
    if (isEmpty(sp)) {
        return 1;
    }
    else {
        return 0;
    }
}
