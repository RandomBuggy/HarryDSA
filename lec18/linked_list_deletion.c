#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} linked_list;

void LinkedListTraversal(linked_list*);

linked_list* DeleteAtFirst(linked_list*);

linked_list* DeleteAtIndex(linked_list*, int);

linked_list* DeleteAtEnd(linked_list*);

linked_list* DeleteAtValue(linked_list*, int);

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

    printf("Linked List before deletion\n");
    LinkedListTraversal(Head);

    //Head = DeleteAtFirst(Head);

    //printf("Linked List after deletion\n");
    //LinkedListTraversal(Head);

    //Head = DeleteAtIndex(Head, 1);
    //printf("Linked List after deletion\n");
    //LinkedListTraversal(Head);

    //Head = DeleteAtEnd(Head);
    //printf("Linked List after deletion\n");
    //LinkedListTraversal(Head);

    Head = DeleteAtValue(Head, 11);
    printf("Linked List after deletion\n");
    LinkedListTraversal(Head);
    return 0;
}

void LinkedListTraversal(linked_list* ptr) {

    while (ptr != NULL) {
        printf("Element : %d\n", ptr -> data);
        ptr = ptr -> next;
    }
}

linked_list* DeleteAtFirst(linked_list* head) {
    linked_list* ptr = head;
    head = head -> next;
    free(ptr);
    return head;
}

linked_list* DeleteAtIndex(linked_list* head, int index) {
    linked_list* p = head;
    linked_list* q = head -> next;
    for (int i = 0; i < index -1; i++) {
        p = p -> next;
        q = q -> next;
    }

    p -> next = q -> next;
    free(q);
    return head;
}

linked_list* DeleteAtEnd(linked_list* head) {
    linked_list* p = head;
    linked_list* q = head -> next;

    while (q -> next != NULL) {
        p = p -> next;
        q = q -> next;
    }

    p -> next = NULL;
    free(q);
    return head;
}

linked_list* DeleteAtValue(linked_list* head, int value) {
    linked_list* p = head;
    linked_list* q = head -> next;

    while (q -> data != value && q -> next != NULL) {
        p = p -> next;
        q = q -> next;
    }

    if (q -> data == value) {
        p -> next = q -> next;
        free(q);
    }

    return head;
}
