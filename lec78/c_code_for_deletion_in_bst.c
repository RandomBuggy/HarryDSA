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

void pre_order(Node *node_ptr) {
  if (node_ptr != NULL) {
    printf("%d ", node_ptr->data);
    pre_order(node_ptr->left);
    pre_order(node_ptr->right);
  }
}

void in_order(Node *node_ptr) {
  if (node_ptr != NULL) {
    in_order(node_ptr->left);
    printf("%d ", node_ptr->data);
    in_order(node_ptr->right);
  }
}

void post_order(Node *node_ptr) {
  if (node_ptr != NULL) {
    post_order(node_ptr->left);
    post_order(node_ptr->right);
    printf("%d ", node_ptr->data);
  }
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

Node *in_order_predecessor(Node *node_ptr) {
  node_ptr = node_ptr->left;
  while (node_ptr->right != NULL) {
    node_ptr = node_ptr->right;
  }
  return node_ptr;
}

Node *delete_bst(Node *node_ptr, int value) {
  Node *in_order_pre;
  if (node_ptr == NULL) {
    return NULL;
  }

  if (node_ptr->left == NULL && node_ptr->right == NULL) {
    free(node_ptr);
    return NULL;
  }
  // search for the target node
  if (value < node_ptr->data) {
    node_ptr->left = delete_bst(node_ptr->left, value);
  } else if (value > node_ptr->data) {
    node_ptr->right = delete_bst(node_ptr->right, value);
  }
  // deletion strategy - node found
  else {
    in_order_pre = in_order_predecessor(node_ptr);
    node_ptr->data = in_order_pre->data;
    node_ptr->left = delete_bst(node_ptr->left, in_order_pre->data);
  }
  return node_ptr;
}

int main(void) {
  Node *parent = create_node(5);
  /* l - left, r - right */
  Node *childl = create_node(2);
  Node *childr = create_node(6);
  /* ll - left of left, rr - right of right */
  Node *childll = create_node(1);
  Node *childrr = create_node(4);

  parent->left = childl;
  parent->right = childr;

  childl->left = childll;
  childl->right = childrr;

  in_order(parent);
  Node *deleted = delete_bst(parent, 2);
  printf("\n");
  in_order(parent);
  printf("\n");
  printf("deleted data: %d integer\n", deleted->data);
  return 0;
}
