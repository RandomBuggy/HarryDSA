#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 4

typedef struct circular_queue {
    int size;
    int f;
    int r;
    int* array;
} CircularQueue;

// prototype
int isEmpty(CircularQueue*);
int isFull(CircularQueue*);
void enqueue(CircularQueue*, int);
int dequeue(CircularQueue*);

int main(void) {
    CircularQueue q;
    q.size = QUEUE_SIZE;
    q.f = 0, q.r = 0;
    q.array = (int*) malloc(q.size * sizeof(int));
    

    printf("Full : %d\n", isFull(&q));
    printf("Empty : %d\n", isEmpty(&q));
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 18);
    enqueue(&q, 11);
    printf("Empty : %d\n", isEmpty(&q));
    printf("Full : %d\n", isFull(&q));
    printf("dequeue : %d\n", dequeue(&q));
    printf("dequeue : %d\n", dequeue(&q));
    printf("dequeue : %d\n", dequeue(&q));
    printf("dequeue : %d\n", dequeue(&q));
    printf("Empty : %d\n", isEmpty(&q));
    printf("Full : %d\n", isFull(&q));
    return 0;
}

int isFull(CircularQueue* qp) {
    return (((qp -> r + 1) % qp -> size) == qp -> f) ? 1 : 0;
}

int isEmpty(CircularQueue* qp) {
    return (qp -> f == qp -> r) ? 1 : 0;
}

void enqueue(CircularQueue* qp, int value) {
    if (isFull(qp)) {
        printf("Queue Overflow\n");
    }
    else {
        printf("Enqueue : %d\n", value);
        qp -> r = (qp -> r + 1) % qp -> size;
        qp -> array[qp -> r] = value;
    }
}

int dequeue(CircularQueue* qp) {
    if (isEmpty(qp)) {
        printf("Queue Underflow\n");
        return -1;
    }
    else {
        qp -> f++;
        return qp -> array[qp -> f];
    }
}
