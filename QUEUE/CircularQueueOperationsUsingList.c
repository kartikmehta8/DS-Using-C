#include <stdio.h>
#define MAX 10

int queue[MAX];

int front = -1, rear = -1;

int isFull() {
    if ((front == rear + 1) || (front == 0 && rear == MAX-1)) return 1;
    else return 0;
}

int isEmpty() {
    if (front == -1) return 1;
    else return 0;
}

void enQueue(int data) {
    if (isFull() == 1) printf("Overflow - Queue is Full!\n");
    else {
        if (front == -1) front = 0;
        rear = (rear+1)%MAX;
        queue[rear] = data;
    }
}

void deQueue() {
    if (isEmpty() == 1) printf("Underflow - Queue is Empty!\n");
    else {
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front+1)%MAX;
        }
    }
}

int PEEK() {
    if (isEmpty() == 1) {
        printf("Underflow - Queue is Empty!\n");
        return -1;
    } else return queue[front];
}

void printQueue() {
    if (isEmpty() == 1) printf("Underflow - Queue is Empty!\n");
    else {
        int i;
        for (i = front; i != rear; i = (i+1)%MAX) printf("%d ", queue[i]);
        printf("%d", queue[i]);
        printf("\n");
    }
}

int main() {
    
    enQueue(1);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    enQueue(5);
    printQueue();
    deQueue();
    deQueue();
    printQueue();
    enQueue(6);
    enQueue(7);
    enQueue(8);
    enQueue(9);
    enQueue(10);
    enQueue(11);
    enQueue(12);
    printQueue();
    enQueue(13);

    return 0;
}