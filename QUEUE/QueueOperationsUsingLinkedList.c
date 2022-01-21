#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void printQueue() {
    if (front == NULL) printf("Underflow - Queue is Empty!\n");
    else {
        struct Node* traverse = front;
        while (traverse != NULL) {
            printf("%d ", traverse->data);
            traverse= traverse->next;
        }
        printf("\n");
    }
}

void enQueue(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (front == NULL) {
        front = newNode;
        rear = front;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void deQueue() {
    if (front  == NULL) printf("Underflow - Queue is Empty!\n");
    else {
        struct Node* toDeleteNode = front;
        front = front->next;
        free(toDeleteNode);
    }
}

int isEmpty() {
    if (front == NULL) return 1;
    else return 0;
}

int main() {
    
    if (isEmpty() == 1) printf("QUEUE IS EMPTY!\n");
    else printf("QUEUE IS NOT EMPTY!\n");
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
    printQueue();
    deQueue();
    deQueue();
    deQueue();
    deQueue();
    deQueue();
    deQueue();

    return 0;
}
