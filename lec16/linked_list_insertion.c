#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} linked_list;

void LinkedListTraversal(linked_list*);

linked_list* InsertAtBeginning(linked_list*, int);

linked_list* InsertAtIndex(linked_list*, int, int);

linked_list* InsertAtEnd(linked_list*, int);

void InsertAfterNode(linked_list*, int);

int main(void) {
    linked_list* Head;
    linked_list* second;
    linked_list* third;
    linked_list* fourth;

    Head = (linked_list*) malloc(sizeof(linked_list));
    second = (linked_list*) malloc(sizeof(linked_list));
    third = (linked_list*) malloc(sizeof(linked_list));
    fourth = (linked_list*) malloc(sizeof(linked_list));


    Head -> data = 5;
    Head -> next = second;
    second -> data = 11;
    second -> next = third;
    third -> data = 13;
    third -> next = fourth;
    fourth -> data = 17;
    fourth -> next = NULL;

    //LinkedListTraversal(Head);
    //printf("\n");

    //Head = InsertAtBeginning(Head, 19);

    //LinkedListTraversal(Head);

    //printf("\n");
    //Head = InsertAtIndex(Head, 23, 2);
    //LinkedListTraversal(Head);

    //printf("\n");
    //Head = InsertAtEnd(Head, 29);
    LinkedListTraversal(Head);
    printf("\n");
    InsertAfterNode(third, 45);

    LinkedListTraversal(Head);
    return 0;
}

void LinkedListTraversal(linked_list* ptr) {
    while (ptr != NULL) {
        printf("Element : %d\n", ptr -> data);
        ptr = ptr -> next;
    }
}

linked_list* InsertAtBeginning(linked_list* head, int data) {
    linked_list* ptr = (linked_list*) malloc(sizeof(linked_list));

    ptr -> data = data;
    ptr -> next = head;
    return ptr;
}

linked_list* InsertAtIndex(linked_list* head, int data, int index) {
    linked_list* ptr = (linked_list*) malloc(sizeof(linked_list));
    linked_list* p = head;
    int i = 0;

    while (i != index - 1) {
        p = p -> next;
        i++;
    }

    ptr -> data = data;
    ptr -> next = p -> next;
    p -> next = ptr;

    return head;
}

linked_list* InsertAtEnd(linked_list* head, int data) {
    linked_list* ptr = (linked_list*) malloc(sizeof(linked_list));
    ptr -> data = data;
    linked_list* p = head;
    while (p != NULL) {
        p = p -> next;
    }

    p -> next = ptr;
    ptr -> next = NULL;

    return head;
}

void InsertAfterNode(linked_list* prevNode, int data) {
    linked_list* ptr = (linked_list*) malloc(sizeof(linked_list));
    ptr -> data = data;
    ptr -> next = prevNode -> next;
    prevNode -> next = ptr;
}
