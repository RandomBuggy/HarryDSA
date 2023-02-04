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

void in_order(Node *node_ptr) {
  if (node_ptr != NULL) {
    in_order(node_ptr->left);
    printf("%d ", node_ptr->data);
    in_order(node_ptr->right);
  }
}

int main(void) {
  Node *parent = create_node(4);
  /* l - left, r - right */
  Node *childl = create_node(1);
  Node *childr = create_node(6);
  /* ll - left of left, rr - right of right */
  Node *childll = create_node(5);
  Node *childrr = create_node(2);

  parent->left = childl;
  parent->right = childr;

  childl->left = childll;
  childl->right = childrr;

  /* traversal - PreOrder */
  in_order(parent);

  return 0;
}
