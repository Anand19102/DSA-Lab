#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char value) {
    if (top == MAX - 1) {
        printf("Stack Overflow cannot push %c\n", value);
    } else {
        top = top + 1;
        stack[top] = value;
    }
}

char pop() {
    if (top == -1) {
        return '\0';
    } else {
        char value = stack[top];
        top = top - 1;
        return value;
    }
}

int isEmpty() {
    return (top == -1);
}

char peek() {
    if (isEmpty()) {
        return '\0';
    }
    return stack[top];
}

int precedence(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char c;

    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

        if (isalnum(c)) {
            postfix[j] = c;
            j++;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[j] = pop();
                j++;
            }
            pop();
        }
        else {
            if (c == '^') {
                while (!isEmpty() && precedence(peek()) > precedence(c)) {
                    postfix[j] = pop();
                    j++;
                }
            } 
            else { 
                while (!isEmpty() && precedence(peek()) >= precedence(c)) {
                    postfix[j] = pop();
                    j++;
                }
            }
            push(c);
        }
    }

    while (!isEmpty()) {
        postfix[j] = pop();
        j++;
    }

    postfix[j] = '\0';
}

int evaluatePostfix(char postfix[]) {
    int stack2[MAX];
    int top2 = -1;
    int i;

    for (i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isdigit(c)) {
            int num = c - '0';
            top2++;
            stack2[top2] = num;
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
            stack2[top2] = result;
        }
    }

    return stack2[top2];
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression (use single digits only): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("\nPostfix Expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Evaluated Result: %d\n", result);

    return 0;
}