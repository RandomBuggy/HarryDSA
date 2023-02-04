#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}doubly_linked_list;

void DoublyLinkedListTraversal(doubly_linked_list*);

int main(void) {
    doubly_linked_list* Head;
    doubly_linked_list* second;
    doubly_linked_list* third;
    doubly_linked_list* fourth;

    Head = (doubly_linked_list*) malloc(sizeof(doubly_linked_list));
    second = (doubly_linked_list*) malloc(sizeof(doubly_linked_list));
    third = (doubly_linked_list*) malloc(sizeof(doubly_linked_list));
    fourth = (doubly_linked_list*) malloc(sizeof(doubly_linked_list));


    Head -> data = 1;
    Head -> next = second;
    Head -> prev = NULL;

    second -> data = 2;
    second -> next = third;
    second -> prev = Head;

    third -> data = 3;
    third -> next = fourth;
    third -> prev = second;

    fourth -> data = 4;
    fourth -> next = NULL;
    fourth -> prev = third;

    DoublyLinkedListTraversal(Head);
    return 0;
}

void DoublyLinkedListTraversal(doubly_linked_list* head) {
    doubly_linked_list* ptr = head;
    doubly_linked_list* p = head;

    while (ptr != NULL) {
        printf("Forward Traversal : %d\n", ptr -> data);
        ptr = ptr -> next;
    }

    printf("\n");

    while(p -> next != NULL) {
        p = p -> next;
    }

    while(p != NULL) {
        printf("Reversed Traversal : %d\n", p -> data);
        p = p -> prev;
    }

    /* ptr = ptr -> prev;
    do {
        printf("Reversed Traversal : %d\n", ptr -> data);
        ptr = ptr -> prev;
    } while(ptr != head); */
}
