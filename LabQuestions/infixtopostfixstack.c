#include <stdio.h>
#include <ctype.h>   // For isdigit(), isalpha()
#include <string.h>
#include <math.h>

#define MAX 100

// Stack for characters (operators)
char stack[MAX];
int top = -1;

// Stack Functions
void push(char value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %c\n", value);
    } else {
        top = top + 1;       // increment top
        stack[top] = value;  // place element
    }
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return '\0';
    } else {
        char value = stack[top]; // take top element
        top = top - 1;           // decrement top
        return value;
    }
}

int isEmpty() {
    return (top == -1);
}

char peek() {
    return stack[top];
}

// Function to get precedence of operators
int precedence(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return 0;
}

// Convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char c;

    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

        // If operand (letter or number), add to postfix
        if (isalnum(c)) {
            postfix[j] = c;
            j++;
        }

        // If '(', push to stack
        else if (c == '(') {
            push(c);
        }

        // If ')', pop until '('
        else if (c == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[j] = pop();
                j++;
            }
            pop(); // remove '('
        }

        // If operator
        else {
            while (!isEmpty() && precedence(peek()) >= precedence(c)) {
                postfix[j] = pop();
                j++;
            }
            push(c);
        }
    }

    // Pop all remaining operators
    while (!isEmpty()) {
        postfix[j] = pop();
        j++;
    }

    postfix[j] = '\0';  // null-terminate the string
}

// Evaluate Postfix Expression
int evaluatePostfix(char postfix[]) {
    int stack2[MAX];
    int top2 = -1;
    int i;

    for (i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isdigit(c)) {
            int num = c - '0';           // convert char to int
            top2++;
            stack2[top2] = num;          // push number to stack2
        } 
        else {
            int b = stack2[top2];
            top2--;
            int a = stack2[top2];
            top2--;

            int result;
            switch (c) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                case '^': result = pow(a, b); break;
                default: result = 0;
            }

            top2++;
            stack2[top2] = result;       // push result back to stack
        }
    }

    return stack2[top2];
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression (use digits only): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("\nPostfix Expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Evaluated Result: %d\n", result);

    return 0;
}
