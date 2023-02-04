#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int size;
    int f;
    int r;
    int* array;
} Queue;

// prototype
int isEmpty(Queue*);
int isFull(Queue*);
void enqueue(Queue*, int);
int dequeue(Queue*);

int main(void) {
    Queue q;
    q.size = 2;
    q.f = -1, q.r = -1;
    q.array = (int*) malloc(q.size * sizeof(int));
    

    printf("Full : %d\n", isFull(&q));
    printf("Empty : %d\n", isEmpty(&q));
    enqueue(&q, 12);
    enqueue(&q, 15);
    printf("Empty : %d\n", isEmpty(&q));
    printf("Full : %d\n", isFull(&q));
    printf("dequeue : %d\n", dequeue(&q));
    printf("dequeue : %d\n", dequeue(&q));
    printf("Empty : %d\n", isEmpty(&q));
    return 0;
}

int isFull(Queue* qp) {
    return (qp -> r == qp -> size - 1) ? 1 : 0;
}

int isEmpty(Queue* qp) {
    return (qp -> f == qp -> r) ? 1 : 0;
}

void enqueue(Queue* qp, int value) {
    if (isFull(qp)) {
        printf("Queue Overflow\n");
    }
    else {
        qp -> r++;
        qp -> array[qp -> r] = value;
    }
}

int dequeue(Queue* qp) {
    if (isEmpty(qp)) {
        printf("Queue Underflow\n");
        return -1;
    }
    else {
        qp -> f++;
        return qp -> array[qp -> f];
    }
}
