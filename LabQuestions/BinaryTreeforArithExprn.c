#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Node of expression tree
struct Node {
    char data;
    struct Node *left, *right;
};

// Stack for nodes
#define MAX 100
struct Node* stack[MAX];
int top = -1;

// Stack operations
void push(struct Node* node) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = node;
}

struct Node* pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return NULL;
    }
    return stack[top--];
}

// Check if character is operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Create new node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build expression tree from postfix expression
struct Node* buildExpressionTree(char postfix[]) {
    struct Node* node, *left, *right;
    int i;
    for (i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isalnum(c)) { // operand
            node = createNode(c);
            push(node);
        } else if (isOperator(c)) { // operator
            node = createNode(c);
            right = pop();
            left = pop();
            node->left = left;
            node->right = right;
            push(node);
        }
    }

    return pop(); // root of expression tree
}

// Preorder traversal → prefix
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal → postfix
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}

// Inorder traversal → for checking tree correctness
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
    }
}

int main() {
    char postfix[100];

    printf("Enter a postfix expression (operands single letters or digits): ");
    scanf("%s", postfix);

    struct Node* root = buildExpressionTree(postfix);

    printf("Inorder (for checking tree correctness): ");
    inorder(root);
    printf("\n");

    printf("Prefix expression: ");
    preorder(root);
    printf("\n");

    printf("Postfix expression: ");
    postorder(root);
    printf("\n");

    return 0;
}
