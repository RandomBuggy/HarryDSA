#include <stdbool.h>
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

bool isBST(Node *node_ptr) {
  static Node *prev = NULL;
  if (node_ptr != NULL) {
    if (!isBST(node_ptr->left)) {
      return false;
    }
    if (prev != NULL && node_ptr->data < prev->data) {
      return false;
    }
    prev = node_ptr;
    return isBST(node_ptr->right);
  } else {
    return true;
  }
}

int main(void) {
  Node *parent = create_node(5);
  /* l - left, r - right */
  Node *childl = create_node(3);
  Node *childr = create_node(6);
  /* ll - left of left, rr - right of right */
  Node *childll = create_node(1);
  Node *childlr = create_node(4);

  parent->left = childl;
  parent->right = childr;

  childl->left = childll;
  childl->right = childlr;

  /* traversal - PreOrder */
  in_order(parent);
  printf("%d", isBST(parent));

  return 0;
}
