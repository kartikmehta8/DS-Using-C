#include <stdio.h>
#define MAX 10

// Globally declared stack which can be accessed in any function.
int stack[MAX];

// Top variable to track the elements of a stack.
int top = -1;

// A function to print the stack.
void printStack() {
    if (top == -1) printf("Underflow - No elements in stack!\n");
    else {
        for (int i = 0; i < top+1; i++) printf("%d ", stack[i]);
        printf("\n");
    }
}

// Function for PUSH Operation.
void PUSH(int data) {
    if (top == MAX-1) printf("Overflow - Stack is full!\n");
    else {
        top++;
        stack[top] = data;
    }
}

// Function for POP Operation.
void POP() {
    if (top == -1) printf("Underflow - No elements in stack!\n");
    else top--;
}

// Fucntion for PEEK Operation.
int PEEK() {
    if (top == -1) {
        printf("Underflow - No elements in stack!\n");
        return -1;
    } else {
        return stack[top];
    }
}

// Function to check if Stack is full or not.
int isFull() {
    if (top == MAX-1) return 1;
    else return 0;
}

// Function to check if Stack is empty or not.
int isEmpty() {
    if (top == -1) return 1;
    else return 0;
}

int main() {
    
    // STACK ALL OPERATIONS USING ARRAY-STACK
    
    if (isEmpty() == 1) printf("STACK IS EMPTY!\n");
    printStack();
    PUSH(1);
    PUSH(2);
    PUSH(3);
    PUSH(4);
    PUSH(5);
    printStack();
    PUSH(6);
    PUSH(7);
    PUSH(8);
    PUSH(9);
    PUSH(10);
    printStack();
    PUSH(11);
    POP();
    if (isFull() == 1) printf("STACK IS FULL!\n");
    else printf("STACK IS NOT FULL!\n");
    POP();
    int peek_element = PEEK();
    printf("PEEKED ELEMENT : %d", peek_element);

    return 0;
}

// OUTPUT ->
// STACK IS EMPTY!
// Underflow - No elements in stack!
// 1 2 3 4 5 
// 1 2 3 4 5 6 7 8 9 10 
// Overflow - Stack is full!
// STACK IS NOT FULL!
// PEEKED ELEMENT : 8