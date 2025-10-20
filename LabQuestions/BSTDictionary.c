#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char word[50];
    char meaning[100];
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(char *word, char *meaning) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->word, word);
    strcpy(newNode->meaning, meaning);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a new word-meaning pair
struct Node* insert(struct Node* root, char *word, char *meaning) {
    if (root == NULL)
        return createNode(word, meaning);

    int cmp = strcmp(word, root->word);
    if (cmp < 0)
        root->left = insert(root->left, word, meaning);
    else if (cmp > 0)
        root->right = insert(root->right, word, meaning);
    else
        printf("Word already exists! Updating meaning...\n"), strcpy(root->meaning, meaning);
    
    return root;
}

// Search for a word
struct Node* search(struct Node* root, char *word) {
    if (root == NULL)
        return NULL;

    int cmp = strcmp(word, root->word);
    if (cmp == 0)
        return root;
    else if (cmp < 0)
        return search(root->left, word);
    else
        return search(root->right, word);
}

// Find minimum node (used in delete)
struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Delete a word from dictionary
struct Node* deleteWord(struct Node* root, char *word) {
    if (root == NULL) {
        printf("Word not found!\n");
        return NULL;
    }

    int cmp = strcmp(word, root->word);

    if (cmp < 0)
        root->left = deleteWord(root->left, word);
    else if (cmp > 0)
        root->right = deleteWord(root->right, word);
    else {
        // Node to delete found
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct Node* temp = findMin(root->right);
        strcpy(root->word, temp->word);
        strcpy(root->meaning, temp->meaning);
        root->right = deleteWord(root->right, temp->word);
    }

    return root;
}

// Display dictionary in sorted (alphabetical) order
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%s : %s\n", root->word, root->meaning);
        inorder(root->right);
    }
}

// Main Function
int main() {
    struct Node* root = NULL;
    int choice;
    char word[50], meaning[100];
    struct Node* temp;

    while (1) {
        printf("\n=== DICTIONARY USING BST ===\n");
        printf("1. Insert Word\n2. Search Word\n3. Delete Word\n4. Display Dictionary\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear buffer (still needed after scanf)

        switch (choice) {
            case 1:
                printf("Enter word: ");
                fgets(word, 50, stdin); // Changed from gets
                word[strcspn(word, "\n")] = 0; // Remove newline

                printf("Enter meaning: ");
                fgets(meaning, 100, stdin); // Changed from gets
                meaning[strcspn(meaning, "\n")] = 0; // Remove newline
                
                root = insert(root, word, meaning);
                break;

            case 2:
                printf("Enter word to search: ");
                fgets(word, 50, stdin); // Changed from gets
                word[strcspn(word, "\n")] = 0; // Remove newline

                temp = search(root, word);
                if (temp)
                    printf("Meaning of '%s': %s\n", temp->word, temp->meaning);
                else
                    printf("Word not found!\n");
                break;

            case 3:
                printf("Enter word to delete: ");
                fgets(word, 50, stdin); // Changed from gets
                word[strcspn(word, "\n")] = 0; // Remove newline

                root = deleteWord(root, word);
                break;

            case 4:
                printf("\n--- Dictionary (Alphabetical Order) ---\n");
                inorder(root);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}