#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* root = NULL;

void printDList() {
    if (root == NULL) printf("Underflow - List is Empty!\n");
    else {
        struct Node* traverse = root;
        while(traverse != NULL) {
            printf("%d ", traverse->data);
            traverse = traverse->next;
        }
        printf("\n");
    }
}

void printDListReverse() {
    if (root == NULL) printf("Underflow - List is Empty!\n");
    else {
        struct Node* traverse = root;
        while(traverse->next != NULL) traverse = traverse->next;
        while (traverse != NULL) {
            printf("%d ", traverse->data);
            traverse = traverse->prev;
        }
        printf("\n");
    }
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtBeginning(int data) {
    struct Node* insertNode = createNode(data);
    
    if (root == NULL) {
        root = insertNode;
    } else {
        root->prev = insertNode;
        insertNode->next = root;
        root = insertNode;
    }
}

void insertAtLast(int data) {
    struct Node* insertNode = createNode(data);
    
    if (root == NULL) {
        root = insertNode;
    } else {
        struct Node* traverse = root;
        while (traverse->next != NULL) {
            traverse = traverse->next;
        }
        traverse->next = insertNode;
        insertNode->prev = traverse;
    }
}

void insertAtPosition(int data, int pos) {
    
    int total_nodes = 0;
    struct Node* traverse = root;
    while (traverse != NULL) {
        total_nodes++;
        traverse = traverse->next;
    }
    
    if (root == NULL) {
        insertAtBeginning(data);
        return;
    }
    
    if (pos > total_nodes) insertAtLast(data);
    else if (pos <= 1) insertAtBeginning(data);
    else {
        traverse = root;
        pos--;
        pos--;
        while (pos) {
            traverse = traverse->next;
            pos--;
        }
        
        struct Node* insertNode = createNode(data);
        struct Node* temp = traverse->next;
        traverse->next = insertNode;
        insertNode->prev = traverse;
        insertNode->next = temp;
        temp->prev = insertNode;
    }
    
}

void deleteAtBeginning() {
    if (root == NULL) printf("Underflow - List is Empty!\n");
    else {
        struct Node* temp = root;
        root = root->next;
        root->prev = NULL;
        free(temp);
    }
}

void deleteAtLast() {
    if (root == NULL) printf("Underflow - List is Empty!\n");
    else if (root->next == NULL){
        struct Node* temp = root;
        root = NULL;
        free(temp);
    } else {
        struct Node* traverse = root;
        while (traverse->next->next != NULL) {
            traverse = traverse->next;
        }
        struct Node* temp = traverse->next;
        traverse->next = NULL;
        free(temp);
    }
}

void deleteAtPosition(int pos) {
    
    int total_nodes = 0;
    struct Node* traverse = root;
    while (traverse != NULL) {
        total_nodes++;
        traverse = traverse->next;
    }
    
    if (root == NULL) {
        printf("Underflow - List is Empty!\n");
        return;
    }
    
    if (pos >= total_nodes) deleteAtLast();
    else if (pos <= 1) deleteAtBeginning();
    else {
        traverse = root;
        pos--;
        pos--;
        while (pos) {
            traverse = traverse->next;
            pos--;
        }
        struct Node* temp = traverse->next;
        traverse->next = temp->next;
        temp->next->prev = traverse;
        free(temp);
    }
    
}

int main() {
    
    insertAtBeginning(3);
    insertAtBeginning(2);
    insertAtBeginning(1);
    insertAtLast(4);
    insertAtLast(5);
    insertAtBeginning(0);
    printDList();
    printDListReverse();
    insertAtPosition(-1, 8);
    insertAtPosition(-2, 1);
    insertAtPosition(-5, 4);
    printDList();
    printDListReverse();
    deleteAtBeginning();
    deleteAtBeginning();
    deleteAtLast();
    deleteAtLast();
    insertAtLast(6);
    insertAtLast(7);
    insertAtLast(8);
    insertAtLast(9);
    insertAtLast(10);
    deleteAtLast();
    deleteAtBeginning();
    deleteAtPosition(1);
    deleteAtPosition(2);
    deleteAtPosition(5);
    printDList();
    printDListReverse();

    return 0;
}
