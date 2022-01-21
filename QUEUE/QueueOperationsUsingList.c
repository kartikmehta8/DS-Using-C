#include <stdio.h>
#define MAX 10

int queue[MAX];

// Initializing the front and rear pointers.
int front = -1, rear = -1;

// Printing the queue.
void printQueue() {
    if (front == -1 || front > rear) printf("Underflow - Queue is Empty!\n");
    else if (front == rear) printf("%d ", queue[rear]);
    else {
        for (int i = front; i < rear+1; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
    
}

// Inserting the element into queue.
void enQueue(int data) {
    if (front == -1) {
        front = 0;
        rear = 0;
        queue[rear] = data;
    } else {
        if (rear == MAX-1) printf("Overflow - Queue is Full!\n");
        else {
            rear++;
            queue[rear] = data;
        }
    }
}

// Function for deletion of front element.
void deQueue() {
    if (front == -1) printf("Underflow - Queue is Empty!\n");
    else if (front == MAX-1) printf("Cannot DeQueue Any More!\n");
    else front++;
}

// Accessing the front element.
int PEEK() {
    if (front == -1) printf("Underflow - Queue is Empty!\n");
    else return queue[front];
}

int isFull() {
    if (rear == MAX-1) return 1;
    else return 0;
}

int isEmpty() {
    if (front == -1) return 1;
    else return 0;
}

int main() {
    
    // QUEUE IMPLEMENTATION USING ARRAY
    
    if (isEmpty() == 1) printf("QUEUE IS EMPTY!\n");
    else printf("QUEUE IS NOT EMPTY!\n");
    enQueue(1);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    enQueue(5);
    printQueue();
    if (isFull() == 1) printf("QUEUE IS FULL!\n");
    else printf("QUEUE IS NOT FULL!\n");
    enQueue(6);
    enQueue(7);
    enQueue(8);
    enQueue(9);
    enQueue(10);
    printQueue();
    enQueue(11);
    deQueue();
    deQueue();
    deQueue();
    deQueue();
    deQueue();
    deQueue();
    deQueue();
    deQueue();
    deQueue();
    deQueue();
    printf(" %d ", front);
    int peek_element = PEEK();
    printf("PEEK ELEMENT : %d", peek_element);

    return 0;
}

// OUTPUT ->
// QUEUE IS EMPTY!
// 1 2 3 4 5 
// QUEUE IS NOT FULL!
// 1 2 3 4 5 6 7 8 9 10 
// Overflow - Queue is Full!
// PEEK ELEMENT : 3