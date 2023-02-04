#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} linked_list;

void LinkedListTraversal(linked_list*);

linked_list* InsertAtFirst(linked_list*, int);

int main() {
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
    fourth -> next = Head;

    LinkedListTraversal(Head);
    printf("\n");
    Head = InsertAtFirst(Head, 2);
    LinkedListTraversal(Head);
    return 0;
}

void LinkedListTraversal(linked_list* head) {
    linked_list* ptr = head;

    /* using while loop

    printf("Element : %d\n", ptr -> data);
    ptr = ptr -> next;
    
    while (ptr != head) {
        printf("Element : %d\n", ptr -> data);
        ptr = ptr -> next;
    }

    */

    // using do-while loop

    do {
        printf("Element : %d\n", ptr -> data);
        ptr = ptr -> next;
    } while (ptr != head);
}

linked_list* InsertAtFirst(linked_list* head, int data) {
    linked_list* ptr = (linked_list*) malloc(sizeof(linked_list));
    ptr -> data = data;
    linked_list* p = head -> next;

    while (p -> next != head) {
        p = p -> next;
    }

    p -> next = ptr;
    ptr -> next = head;
    head = ptr;
    return head;
}
