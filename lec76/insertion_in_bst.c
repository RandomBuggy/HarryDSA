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

Node *iter_search_bst(Node *node_ptr, int key) {

  while (node_ptr != NULL) {
    if (node_ptr->data == key)
      return node_ptr;

    else if (key < node_ptr->data)
      node_ptr = node_ptr->left;
    else
      node_ptr = node_ptr->right;
  }
  return NULL;
}

void insertion_bst(Node *node_ptr, int key) {
  Node *prev = NULL, *ptr;
  while (node_ptr != NULL) {
    prev = node_ptr;
    if (key == node_ptr->data) {
      printf("Duplicate Value: %d, Can't Insert\n", key);
      return;
    } else if (key < node_ptr->data) {
      node_ptr = node_ptr->left;
    } else {
      node_ptr = node_ptr->right;
    }
  }
  ptr = create_node(key);
  if (key < prev->data) {
    prev->left = ptr;
  } else {
    prev->right = ptr;
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

  insertion_bst(parent, 16);

  printf("Inserted Value: %d\n", parent->right->right->data);

  return 0;
}
