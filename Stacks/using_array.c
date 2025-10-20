#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Global variables for the stack
int stack[MAX_SIZE];
int top = -1; // Initialize an empty stack

// Function to push an element onto the stack
void Push(int element) {
 if (top == MAX_SIZE - 1) {
     printf("Stack overflow: Cannot push element onto a full stack\n");
     return; // Handle overflow (stack is full)
 }
 top++;
 stack[top] = element;
}


// Function to pop an element from the stack
int Pop() {
 if (top == -1) {
     printf("Stack underflow: Cannot pop element from an empty stack\n");
 return -1; // Handle underflow (stack is empty)
 }
 int element = stack[top];
 top--;
 return element;
}


// Function to peek at the top element of the stack
int Peek() {
 if (top == -1) {
     printf("Stack is empty Underflow!\n");
     return -1; // Handle underflow (stack is empty)
 }
 return stack[top];
}


// Function to check if the stack is empty
bool IsEmpty() {
 return (top == -1);
}
void Display()
{ int i;
 if(IsEmpty()) printf("Stack is empty Under flow!\n");
 else
 {
     printf("Stack contents are\n");
     for(i=top;i>=0;i--)
     printf("%d\n",stack[i]);
 }
}
int main() {
int item, choice;
printf("\t\t\tImplementation Of Stack ");

do {

printf("\n\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.exit\n");
printf("\nEnter Your Choice :: ");
scanf("%d", &choice);
switch (choice) {
case 1:
     printf("\nEnter The item to be pushed :: ");
     scanf("%d", &item);
     Push(item);
     break;
case 2:
     if (IsEmpty())
     printf("\nEmpty stack!Underflow !!");
     else {
     item = Pop();
     printf("\nThe popped element is %d", item);
     }
     break;
case 3:
     if (IsEmpty())
     printf("\nEmpty stack!Underflow !!");
     else {
     item = Peek();
     printf("\nThe Top element is %d", item);
     }
     break;
case 4:
     Display();
     break;
case 5:
     exit(0);
    }
} while (1);
return 0;
}
