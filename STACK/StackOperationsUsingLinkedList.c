#include <stdio.h>
#include <stdlib.h>

// Structure of a Node for Stack.
struct Node {
    int data;
    struct Node* next;
};

// Initializing the first Node as root to track the elements in a stack.
struct Node* root = NULL;

// Function to print the Stack.
void printStack() {
    struct Node* traverse = root;
    if (root == NULL) printf("Underflow - Stack is Empty!\n");
    else {
        while (traverse != NULL) {
            printf("%d ", traverse->data);
            traverse = traverse->next;
        }
        printf("\n");
    }
}

// Function to implement the PUSH Operation in Stack.
void PUSH(int data) {
    //Basic Node creation
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    // If no element,then newNode is first Node.
    if (root == NULL) root = newNode;
    else {
        
        //Inserting the Nodes at the very beginning.
        newNode->next = root;
        root = newNode;
    }
}

// Function to implement the POP Operation in Stack.
void POP() {
    if (root == NULL) printf("Underflow - Stack is Empty!\n");
    else {
        struct Node* toDeleteNode = root;
        root = root->next;
        free(toDeleteNode);
    }
}

// Function to implement the PEEK Operation in Stack.
int PEEK() {
    if (root == NULL) printf("Underflow - Stack is Empty!\n");
    else {
        return root->data;
    }
}

// Function to check if stack is empty or not.
int isEmpty() {
    if (root == NULL) return 1;
    else return 0;
}

int main() {
    
    // STACK ALL OPERATIONS USING LINKED LIST - STACK
    
    PUSH(1);
    PUSH(2);
    PUSH(3);
    PUSH(4);
    PUSH(5);
    printStack();
    POP();
    POP();
    POP();
    POP();
    POP();
    printStack();
    PUSH(1);
    PUSH(2);
    PUSH(3);
    printStack();
    POP();
    int peek_element = PEEK();
    printf("PEEK ELEMENT : %d", peek_element);

    return 0;
}

// OUTPUT ->
// 5 4 3 2 1 
// Underflow - Stack is Empty!
// 3 2 1 
// PEEK ELEMENT : 2