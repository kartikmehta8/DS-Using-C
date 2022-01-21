#include <stdio.h>
#define MAX 20

char stack[MAX];
int top = -1;

void PUSH(char data) {
    if (top == MAX-1) printf("Overflow - Stack is Full!\n");
    else {
        top++;
        stack[top] = data;
    }
}

void POP() {
    if (top == -1) printf("Underflow - Stack is Empty!\n");
    else {
        top--;
    }
}

char PEEK() {
    if (top == -1) printf("Underflow - Stack is Empty!\n");
    else {
        return stack[top];
    }
}


// MAIN REVERSE FUNCTION
void reverse(char *string, int len, char* reverse_str) {
    for (int i = 0; i < len+1; i++) PUSH(string[i]);
    for (int i = 0; i < len+1; i++) {
        char data = PEEK();
        reverse_str[i] = data;
        POP();
    }
}

int main() {
    
    printf("Enter the length of the string : ");
    int len;
    scanf("%d", &len);
    printf("Enter the string : ");
    char string[len];
    char reverse_string[len];
    for (int i = 0; i < len+1; i++) scanf("%c", &string[i]);
    
    printf("The original string : ");
    for (int i = 0; i < len+1; i++) printf("%c", string[i]);
    
    reverse(string, len, reverse_string);
    
    printf("\nThe reversed string : \n");
    for (int i = 0; i < len+1; i++) printf("%c", reverse_string[i]);

    return 0;
}

// OUTPUT ->
// Enter the length of the string : 5   
// Enter the string : mehta
// The original string : 
// mehta
// The reversed string : 
// athem