#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

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

void DFS(int i) {
    int j;
    printf("%d ", i);
    visited[i] = 1;

    for (j = 0; j < SIZE; j++) {
        if (adjMatrix[i][j] && !visited[j]) {
            DFS(j);
        }
    }
}

int main(void) {
    // DFS implementation
    DFS(5);
    printf("\n");
    return 0;
}
