#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#define HEIGHT 1

typedef struct node {
  int key;
  struct node *left;
  struct node *right;
  int height;
} Node;

void pre_order(Node *node_ptr) {
  if (node_ptr != NULL) {
    printf("%d ", node_ptr->key);
    pre_order(node_ptr->left);
    pre_order(node_ptr->right);
  }
}

int get_height(Node *node_ptr) {
  if (node_ptr == NULL) {
    return false;
  }
  return node_ptr->height;
}

Node *create_node(int key) {
  Node *node_ptr = (Node *)malloc(sizeof(Node));

  node_ptr->key = key;
  node_ptr->left = NULL;
  node_ptr->right = NULL;
  node_ptr->height = HEIGHT;

  return node_ptr;
}

int get_balance_factor(Node *node_ptr) {
  if (node_ptr == NULL) {
    return false;
  }
  return get_balance_factor(node_ptr->left) -
         get_balance_factor(node_ptr->right);
}

int max(int a, int b) { return a > b ? a : b; }

Node *right_rotate(Node *y) {
  Node *x = y->left;
  Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(get_height(y->right), get_height(y->left)) + 1;
  x->height = max(get_height(x->right), get_height(x->left)) + 1;

  return x;
}

Node *left_rotate(Node *x) {
  Node *y = x->right;
  Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  y->height = max(get_height(y->right), get_height(y->left)) + 1;
  x->height = max(get_height(x->right), get_height(x->left)) + 1;

  return y;
}

Node *insertion_bst(Node *node_ptr, int key) {

  if (node_ptr == NULL) {
    return create_node(key);
  }

  if (key < node_ptr->key) {
    return insertion_bst(node_ptr->left, key);
  } else if (key > node_ptr->key) {
    return insertion_bst(node_ptr->right, key);
  }

  // for the leaf node
  node_ptr->height =
      1 + max(get_height(node_ptr->left), get_height(node_ptr->right));
  int BF = get_balance_factor(node_ptr);

  // left left case
  if (BF > 1 && key < node_ptr->left->key) {
    return right_rotate(node_ptr);
  }
  // right right case
  if (BF < -1 && key > node_ptr->right->key) {
    return left_rotate(node_ptr);
  }
  // left right case
  if (BF > 1 && key > node_ptr->left->key) {
    node_ptr->left = left_rotate(node_ptr->left);
    return right_rotate(node_ptr);
  }
  // right left case
  if (BF < -1 && key < node_ptr->right->key) {
    node_ptr->right = right_rotate(node_ptr->right);
    return left_rotate(node_ptr);
  }
  return node_ptr;
}

int main(void) {
  Node *root = NULL;
  root = insertion_bst(root, 1);
  root = insertion_bst(root, 2);
  root = insertion_bst(root, 4);
  root = insertion_bst(root, 5);
  root = insertion_bst(root, 6);
  root = insertion_bst(root, 3);

  pre_order(root);
  return 0;
}
