#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* last = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->next = NULL;
    newNode->data = data;
    return newNode;
}

void insertAtFront(int data) {
    struct Node* insertNode = createNode(data);
    
    if (last == NULL) {
        insertNode->next = insertNode;
        last = insertNode;
    } else {
        insertNode->next = last->next;
        last->next = insertNode;
    }
}

void insertAtEnd(int data) {
    struct Node* insertNode = createNode(data);
    
    if (last == NULL) {
        insertNode->next = insertNode;
        last = insertNode;
    } else {
        insertNode->next = last->next;
        last->next = insertNode;
        last = insertNode;
    }
}

void printList() {
    if (last == NULL) printf("Underflow - List is Empty!\n");
    else {
        struct Node* traverse = last->next;
        while (traverse != last) {
            printf("%d ", traverse->data);
            traverse = traverse->next;
        }
        printf("%d ", traverse->data);
        printf("\n");
    }
}

void insertAtPosition(int data, int pos) {
    
    struct Node* traverse = last->next;
    int count_nodes = 0;
    while (traverse != last) {
        count_nodes++;
        traverse = traverse->next;
    }
    count_nodes++;
    
    if (last == NULL) {
        insertAtFront(data);
        return;
    }
    
    if (pos <= 1) insertAtFront(data);
    else if (pos > count_nodes) insertAtEnd(data);
    else {
        struct Node* insertNode = createNode(data);
        traverse = last->next;
        pos--;
        pos--;
        while (pos) {
            traverse = traverse->next;
            pos--;
        }
        struct Node* temp = traverse->next;
        traverse->next = insertNode;
        insertNode->next = temp;
    }
}

void deleteAtFront() {
    if (last == NULL) printf("Underflow - List is Empty!\n");
    else {
        struct Node* temp = last->next;
        last->next = temp->next;
        free(temp);
    }
}

void deleteAtLast() {
    if (last == NULL) printf("Underflow - List is Empty!\n");
    else {
        struct Node* temp = last->next;
        while (temp->next != last) {
            temp = temp->next;
        }
        temp->next = last->next;
        last = temp;
    }
}

void deleteAtPosition(int pos) {
    struct Node* traverse = last->next;
    int count_nodes = 0;
    while (traverse != last) {
        count_nodes++;
        traverse = traverse->next;
    }
    count_nodes++;
    
    if (last == NULL) {
        printf("Underflow - List is Empty!\n");
        return;
    }
    
    if (pos <= 1) deleteAtFront();
    else if (pos >= count_nodes) deleteAtLast();
    else {
        traverse = last->next;
        pos--;
        pos--;
        while (pos) {
            traverse = traverse->next;
            pos--;
        }
        struct Node* temp = traverse->next;
        traverse->next = temp->next;
        free(temp);
    }
}

int main() {
    
    insertAtFront(2);
    insertAtFront(1);
    insertAtEnd(4);
    insertAtEnd(3);
    printList();
    insertAtPosition(-1, 3);
    insertAtPosition(-2, 3);
    printList();
    deleteAtFront();
    deleteAtFront();
    printList();
    deleteAtLast();
    deleteAtLast();
    printList();
    insertAtPosition(3,2);
    insertAtPosition(4,4);
    insertAtPosition(9,7);
    printList();
    deleteAtPosition(5);
    deleteAtPosition(2);
    printList();

    return 0;
}