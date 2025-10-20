#include<stdio.h>    // For standard input/output functions like printf, scanf
#include<stdlib.h>   // For memory allocation (malloc, free) and exit()
#include<ctype.h>    // For the isdigit() function to check for numeric characters

// --- Data Structures ---

// Defines the structure for a single node in the binary expression tree
struct Node {
    char data;                 // Stores an operand (e.g., '5') or an operator (e.g., '+')
    struct Node *left, *right; // Pointers to the left and right children
};

// Defines the structure for a node in the helper stack
// The stack is implemented as a linked list
struct Stack {
    struct Node* data;    // ***Crucially, the stack's data is a POINTER to a tree Node***
    struct Stack* next;   // Pointer to the next element in the stack
};

// A global pointer to keep track of the top of the stack
struct Stack* top = NULL;

// --- Function to Create a Tree Node ---

// Utility function to create a new, isolated tree node
struct Node* createNode(char value) {
    // Allocate memory for one new tree node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value; // Set the data
    // A new node is always a leaf node, so its children are NULL
    newNode->left = newNode->right = NULL;
    return newNode;
}

// --- Stack Operations ---

// Pushes a tree node's pointer onto the stack (LIFO)
void push(struct Node* treeNode) {
    // 1. Create a new stack node
    struct Stack* temp = (struct Stack*)malloc(sizeof(struct Stack));
    // 2. Store the tree node pointer in the stack node's data field
    temp->data = treeNode;
    // 3. The new node's next points to the old top
    temp->next = top;
    // 4. The new node becomes the new top
    top = temp;
}

// Pops a tree node's pointer from the stack (LIFO)
struct Node* pop() {
    // Check for stack underflow (trying to pop from an empty stack)
    if (top == NULL) return NULL;

    // 1. Create a temporary pointer to the current top
    struct Stack* temp = top;
    // 2. Get the tree node pointer that we need to return
    struct Node* res = top->data;
    // 3. Move the top pointer down to the next element
    top = top->next;
    // 4. Free the memory of the old stack node to prevent leaks
    free(temp);
    // 5. Return the pointer to the tree node
    return res;
}

// --- Core Logic: Building the Expression Tree ---

// Constructs an expression tree from a given postfix expression string
struct Node* createExpressionTree(char postfix[]) {
    int i = 0;
    char symbol;

    // Loop through each character of the postfix string
    while ((symbol = postfix[i]) != '\0') {
        // If the character is a digit, it's an OPERAND
        if (isdigit(symbol)) {
            struct Node* operandNode = createNode(symbol);
            push(operandNode); // Push a pointer to the operand node onto the stack
        }
        // Otherwise, the character is an OPERATOR
        else {
            struct Node* operatorNode = createNode(symbol);
            // Pop two operands from the stack
            operatorNode->right = pop(); // The first operand popped is the right child
            operatorNode->left = pop();  // The second operand popped is the left child

            // Push the newly formed subtree (rooted at the operator) back onto the stack
            push(operatorNode);
        }
        i++; // Move to the next character in the string
    }
    // After the loop, the stack will contain exactly one node: the root of the entire tree
    return pop();
}

// --- Tree Traversal Functions ---

// Inorder traversal (Left -> Root -> Right) - produces the INFIX expression
void inorder(struct Node* root) {
    if (root != NULL) {
        // Add parentheses for clarity if it's an operator node (which has children)
        if(root->left && root->right) printf("(");
        
        inorder(root->left);      // Traverse left subtree
        printf("%c", root->data); // Visit the root
        inorder(root->right);     // Traverse right subtree
        
        if(root->left && root->right) printf(")");
    }
}

// Preorder traversal (Root -> Left -> Right) - produces the PREFIX expression
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%c", root->data); // Visit the root
        preorder(root->left);     // Traverse left subtree
        preorder(root->right);    // Traverse right subtree
    }
}

// Postorder traversal (Left -> Right -> Root) - produces the POSTFIX expression
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);    // Traverse left subtree
        postorder(root->right);   // Traverse right subtree
        printf("%c", root->data); // Visit the root
    }
}

// --- Main Driver Function ---

int main() {
    struct Node* root = NULL; // Pointer to the root of the expression tree, initially empty
    int choice;
    char postfix[100]; // A character array to store the user's input expression

    // Infinite loop for the menu, broken by choice 5
    do {
        printf("\nMenu\n----\n");
        printf("1. Create Expression Tree\n");
        printf("2. Inorder Traversal (Infix Expression)\n");
        printf("3. Preorder Traversal (Prefix Expression)\n");
        printf("4. Postorder Traversal (Postfix Expression)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // This is crucial: scanf("%d",...) leaves the newline ('\n') character in the
        // input buffer. getchar() consumes it so the next scanf("%s",...) works correctly.
        getchar();

        switch(choice) {
            case 1:
                printf("Enter postfix expression: ");
                scanf("%s", postfix); // Read the expression string from the user
                root = createExpressionTree(postfix); // Build the tree
                printf("Expression Tree Created Successfully.\n");
                break;
            case 2:
                if(root == NULL) printf("Create the tree first!\n");
                else {
                    printf("Inorder Traversal (Infix): ");
                    inorder(root);
                    printf("\n");
                }
                break;
            case 3:
                if(root == NULL) printf("Create the tree first!\n");
                else {
                    printf("Preorder Traversal (Prefix): ");
                    preorder(root);
                    printf("\n");
                }
                break;
            case 4:
                if(root == NULL) printf("Create the tree first!\n");
                else {
                    printf("Postorder Traversal (Postfix): ");
                    postorder(root);
                    printf("\n");
                }
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0); // Terminate the program
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while(1); // The loop continues until the user chooses to exit

    return 0; // This line is technically unreachable due to exit(0) but is good practice
}