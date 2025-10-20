#include<stdio.h>
#include<stdlib.h>

// Defines the structure for a single tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Creates a new node and returns a pointer to it
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Inserts a value into the BST recursively
struct Node* insert(struct Node* root, int value) {
    // Base Case: If the current subtree is empty, create the new node here.
    if (root == NULL) {
        return createNode(value);
    }
    
    // Recursive Step: Decide whether to go left or right.
    if (value < root->data) {
        // This assignment connects the new node when the recursion unwinds.
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        // This assignment connects the new node when the recursion unwinds.
        root->right = insert(root->right, value);
    }
    
    // Return the root of the current subtree (unchanged in the recursive step).
    return root;
}

// Inorder Traversal (Left, Root, Right) - prints in sorted order
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder Traversal (Root, Left, Right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder Traversal (Left, Right, Root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Main function with user menu
int main() {
    struct Node* root = NULL; // The tree starts empty
    int choice, value;
    
    do {
        printf("\n--- BST Menu ---\n");
        printf("1. Insert a value\n");
        printf("2. Display Inorder Traversal\n");
        printf("3. Display Preorder Traversal\n");
        printf("4. Display Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value); // Update the main root pointer
                printf("%d inserted successfully.\n", value);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        
    } while (choice != 5);
    
    return 0;
}

/*In those recursive functions (insert, inorder, etc.), the root parameter is a local variable that
represents the root of the current subtree the function is operating on.It does not always refer to the main, 
top-level root of the entire tree.

The "You Are Here" Pointer
Think of the root parameter as a "you are here" marker that changes with each recursive call.
Initial Call: When you first call insert(main_root, value) from the main function, the root parameter inside 
insert points to the actual top-level root of your whole tree.
Recursive Calls: When the function calls itself, like insert(root->left, value), it's doing two things:
It's passing the left child as the new entry point for the next step.
Inside that new function call, the root parameter now holds the address of what was the left child in the previous step.
So, root is just the function's name for "whatever node I was told to start with for this specific task."

An Analogy: Delegating a Task
Imagine a CEO (main function) gives a task to a top-level Manager (the initial root node).
The Manager looks at the task. If it's for their department, they handle it.
If not, they delegate the exact same task to one of their subordinate Team Leads (the left or right child).
Now, for that Team Lead, they are the "manager" (root) of their own team (the subtree). They repeat the 
same process, either handling the task or delegating it further down.
The root parameter is just the title "manager" for whoever is currently responsible for the task at each 
level of the hierarchy.




That line root->left = insert(root->left, value); performs the crucial step of linking the new node
 into the tree.
Without the assignment (=), the recursive calls would happen, a new node would be created in memory, 
but it would never be attached to its parent. The assignment is what forges the connection.

What It Actually Does: Two Scenarios
The key is to understand that the insert function always returns a pointer. What it returns is what 
gets assigned. This line handles two different situations.

Scenario 1: Attaching a new leaf node (The important case)
This is when root->left is currently NULL. You've found an empty spot where the new node should go.
The current node (root) sees that its left child is empty (root->left is NULL).
The code calls insert(NULL, value).
This new call immediately hits the base case: if (root == NULL).
It then executes return createNode(value);. This creates a brand new node for your value and 
returns its memory address.
Now, back in the original call, the line becomes:
root->left = [address of the new node];

This is the magic step. The left pointer of the parent node, which was NULL, is now updated to point to the new node. The connection is made.


Scenario 2: Traversing down an existing branch (The "harmless" case)
This is when root->left already points to an existing node.
The code calls insert(root->left, value). This passes the existing left child to the next recursive step.
That recursive call will continue traveling down the tree until it eventually finishes and returns. What does it return? The function always ends with return root;, so it returns the pointer to the node it was given, unchanged.

Back in the original call, the line becomes:
root->left = root->left;

This is like writing x = x;. It's a redundant but harmless assignment.

So, this single line of code elegantly handles both situations. It does nothing when just passing through, but it performs the critical link-up when a new node is created at the end of a branch.
*/