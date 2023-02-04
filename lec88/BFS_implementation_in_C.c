#include <malloc.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

typedef struct {
    int size;
    int f;
    int r;
    int *array;
} Queue;

int isEmpty(Queue *q) {
    return (q->r == q->f) ? 1 : 0;
}

int isFull(Queue *q) {
    return (q->r == q->size - 1) ? 1 : 0;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is Full\n");
    }
    q->r++;
    q->array[q->r] = value;
}

int dequeue(Queue *q) {
    int value = -1;
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
    }
    else {
        q->f++;
        value = q->array[q->f];
    }
    return value;
}

int main(void) {
    // Queue Stuff
    Queue q;
    q.size = 400;
    q.r = q.f = 0;
    q.array = (int*) malloc(q.size * sizeof(int));


    // BFS implementation
    int node, i = 5;
    int visited[SIZE] = {0};
    int adjMatrix[SIZE][SIZE] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };
    printf("%d", i);
    visited[i] = 1;
    enqueue(&q, i); /* enqueue i for exploration */
    
    while (!isEmpty(&q)) {
        node = dequeue(&q);

        for (int j=0; j < SIZE; j++) {
            if (adjMatrix[node][j] == 1 && visited[j] == 0) {
                printf("%d", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
    printf("\n");
    free(q.array);
    return 0;
}
