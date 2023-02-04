#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t *front = NULL;
node_t *rear = NULL;

void linkedListTraversal(node_t *fptr) {
    while (fptr != NULL) {
        printf("element %d\n", fptr -> data);
        fptr = fptr -> next;
    }
}

int isFull(node_t *node) {
    return (node == NULL) ? 1 : 0;
}

int isEmpty(node_t *node) {
    return (node == NULL) ? 1 : 0;
}

void enqueue(int value) {
    node_t *new = (node_t*) malloc(sizeof(node_t));

    if (isFull(new)) printf("Queue Full\n");

    new -> data = value;
    new -> next = NULL;

    if (front == NULL && rear == NULL) front = rear = new;

    rear -> next = new;
    rear = new;
}

int dequeue() {
    int value = -1;
    node_t *tmp = front;

    if (isEmpty(front)) {printf("Queue Empty\n"); return value;}

    front = front -> next;
    value = tmp -> data;
    free(tmp);
    return value;
}

int main(void) {

    printf("dequeued : %d\n", dequeue());
    linkedListTraversal(front);
    enqueue(68);
    enqueue(64);
    enqueue(61);
    linkedListTraversal(front);
    printf("dequeued : %d\n", dequeue());
    printf("dequeued : %d\n", dequeue());
    linkedListTraversal(front);
    printf("dequeued : %d\n", dequeue());
    printf("dequeued : %d\n", dequeue());
    linkedListTraversal(front);
    return 0;
}

