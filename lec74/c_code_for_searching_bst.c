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

Node *search_bst(Node *node_ptr, int key) {
  if (node_ptr == NULL)
    return NULL;

  if (node_ptr->data == key)
    return node_ptr;

  else if (key < node_ptr->data)
    return search_bst(node_ptr->left, key);
  else
    return search_bst(node_ptr->right, key);
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

  Node *result = search_bst(parent, 10);
  if (result != NULL)
    printf("Element found: %d data\n", result->data);
  else
    printf("Element not found: data\n");

  return 0;
}
