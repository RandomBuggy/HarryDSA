#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} linked_list;

void LinkedListTraversal(struct Node*);

int main() {
    //initialization of nodes
    linked_list* head;
    linked_list* second;
    linked_list* third;
    //allocate node from heap
    head = (linked_list*) malloc (sizeof(linked_list));
    second = (linked_list*) malloc(sizeof(linked_list));
    third = (linked_list*) malloc(sizeof(linked_list));

    //linking nodes
    head -> data = 7;
    head -> next = second;
    second -> data = 23;
    second -> next = third;
    third -> data = 67;
    third -> next = NULL;

    //traversal
    LinkedListTraversal(head);
    return 0;
}

void LinkedListTraversal(struct Node* ptr) {
    while (ptr != NULL) {
        printf("Element: %d\n", ptr -> data);
        ptr = ptr -> next;
    }
}

