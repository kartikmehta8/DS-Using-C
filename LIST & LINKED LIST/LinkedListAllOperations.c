#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* root = NULL;

void printList() {
    if (root == NULL) printf("Underflow - List is Empty!\n");
    else {
        struct Node* traverse = root;
        while (traverse != NULL) {
            printf("%d ", traverse->data);
            traverse = traverse->next;
        }
        printf("\n");
    }
}

// Utility function to create the node.
struct Node* crreateNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->next = NULL;
    newNode->data = data;
    return newNode;
}

void insertAtBeginning(int data) {
    struct Node* insertNode = crreateNode(data);
    
    if (root == NULL) {
        root = insertNode;
    } else {
        insertNode->next = root;
        root = insertNode;
    }
}

void insertAtLast(int data) {
    struct Node* insertNode = crreateNode(data);
    
    if (root == NULL) {
        root = insertNode;
    } else {
        struct Node* traverse = root;
        while (traverse->next != NULL) {
            traverse = traverse->next;
        }
        traverse->next = insertNode;
    }
}

void insertAtPosition(int data, int pos) {
    
    // Counting the total Nodes.
    struct Node* traverse = root;
    int total_nodes = 0;
    while (traverse != NULL) {
        total_nodes++;
        traverse = traverse->next;
    }
    
    // If root is NULL then first node is created.
    if (root == NULL) {
        insertAtBeginning(data);
        return;
    }
    
    // If position is greater than total number of nodes, then simply calling insertAtLast() function.
    if (pos > total_nodes) insertAtLast(data);
    // If position is smaller than 0 or it is first position, then simply calling insertAtBeginning().
    else if (pos <= 1) insertAtBeginning(data);
    else {
        traverse = root;
        pos--;
        pos--;
        // Traversing the traverse till it is just behind the position where a Node should be inserted.
        while (pos) {
            traverse = traverse->next;
            pos--;
        }
        struct Node* insertNode = crreateNode(data);
        struct Node* temp = traverse->next;
        traverse->next = insertNode;
        insertNode->next = temp;
    }
    
}

void deleteAtFirst() {
    if (root == NULL) printf("Underflow - List is Empty!\n");
    else {
        struct Node* traverse = root;
        root = root->next;
        free(traverse);
    }
}

void deleteAtLast() {
    if (root == NULL) printf("Underflow - List is Empty!\n");
    else if (root->next == NULL) {
        struct Node* temp = root;
        root = NULL;
        free(temp);
    } else {
        struct Node *traverse = root;
        struct Node *temp = traverse->next;
        while (traverse->next->next != NULL) {
            traverse = traverse->next;
            temp = traverse->next;
        }
        traverse->next = NULL;
        free(temp);
    }
}

void deleteAtPosition(int pos) {
    
    // Counting the total Nodes.
    struct Node* traverse = root;
    int total_nodes = 0;
    while (traverse != NULL) {
        total_nodes++;
        traverse = traverse->next;
    }
    
    if (root == NULL) {
        printf("Underflow - List is Empty!\n");
        return;
    }
    
    if (pos >= total_nodes) deleteAtLast();
    else if (pos <= 1) deleteAtFirst();
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
        free(temp);
    }
}

void printListReverse(struct Node* root) {
    if (root != NULL) {
        printListReverse(root->next);
        printf("%d ", root->data);
    }
}

int main() {
    
    printList();
    insertAtBeginning(2);
    insertAtBeginning(1);
    insertAtLast(3);
    insertAtBeginning(0);
    insertAtLast(4);
    printList();
    insertAtPosition(-1, 5);
    printList();
    deleteAtFirst();
    deleteAtFirst();
    insertAtPosition(-5, 3);
    printList();
    deleteAtLast();
    deleteAtLast();
    printList();
    insertAtPosition(1, 1);
    insertAtPosition(8, 1);
    insertAtPosition(6, 3);
    printList();
    deleteAtPosition(6);
    printList();
    printListReverse(root);
    printf("\n");
    insertAtPosition(9, 2);
    deleteAtLast();
    printList();

    return 0;
}
