#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} Node;

Node *create_node(int data) {
  Node *node_ptr = (Node *)malloc(sizeof(Node));

  node_ptr->data = data;
  node_ptr->left = NULL;
  node_ptr->right = NULL;

  return node_ptr;
}

int main(void) {
  Node *parent = create_node(2);
  Node *child2 = create_node(1);
  Node *child1 = create_node(4);

  parent->left = child1;
  parent->right = child2;

  return 0;
}
