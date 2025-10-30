#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char word[50];
    char meaning[100];
    struct Node *left, *right;
};

struct Node* createNode(char word[], char meaning[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->word, word);
    strcpy(newNode->meaning, meaning);
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct Node* insert(struct Node* root, char word[], char meaning[]) {
    if (root == NULL)
        return createNode(word, meaning);
    
    if (strcmp(word, root->word) < 0)
        root->left = insert(root->left, word, meaning);
    else if (strcmp(word, root->word) > 0)
        root->right = insert(root->right, word, meaning);
    else
        printf("Word '%s' already exists in dictionary.\n", word);

    return root;
}

struct Node* deleteNode(struct Node* root, char word[]) {
    if (root == NULL) return root;

    if (strcmp(word, root->word) < 0)
        root->left = deleteNode(root->left, word);
    else if (strcmp(word, root->word) > 0)
        root->right = deleteNode(root->right, word);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMin(root->right);

        strcpy(root->word, temp->word);
        strcpy(root->meaning, temp->meaning);

        root->right = deleteNode(root->right, temp->word);
    }
    return root;
}

void search(struct Node* root, char word[]) {
    if (root == NULL) {
        printf("Word '%s' not found!\n", word);
        return;
    }

    if (strcmp(word, root->word) == 0)
        printf("Meaning of '%s' is: %s\n", word, root->meaning);
    else if (strcmp(word, root->word) < 0)
        search(root->left, word);
    else
        search(root->right, word);
}

void update(struct Node* root, char word[]) {
    if (root == NULL) {
        printf("Word '%s' not found, cannot update.\n", word);
        return;
    }

    if (strcmp(word, root->word) == 0) {
        char newMeaning[100];
        printf("Enter new meaning for '%s': ", word);
        fgets(newMeaning, sizeof(newMeaning), stdin);
        newMeaning[strcspn(newMeaning, "\n")] = '\0';

        strcpy(root->meaning, newMeaning);
        printf("Meaning updated successfully.\n");
    }
    else if (strcmp(word, root->word) < 0)
        update(root->left, word);
    else
        update(root->right, word);
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%s : %s\n", root->word, root->meaning);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice;
    char word[50], meaning[100];
    
    do {
        printf("\n--- Dictionary Menu ---\n");
        printf("1. Insert Word\n2. Search Word\n3. Display Dictionary\n4. Update Word\n5. Delete Word\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                printf("Enter Word: ");
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = '\0'; 

                printf("Enter Meaning: ");
                fgets(meaning, sizeof(meaning), stdin);
                meaning[strcspn(meaning, "\n")] = '\0'; 

                root = insert(root, word, meaning);
                break;
            case 2:
                printf("Enter Word to Search: ");
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = '\0'; 
                
                if (root == NULL)
                    printf("Dictionary is empty.\n");
                else
                    search(root, word);
                break;
            case 3:
                printf("\n--- Dictionary Words (Alphabetical) ---\n");
                if (root == NULL)
                    printf("Dictionary is empty.\n");
                else
                    inorder(root);
                break;
            case 4:
                printf("Enter Word to Update: ");
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = '\0'; 
                
                if (root == NULL)
                    printf("Dictionary is empty.\n");
                else
                    update(root, word);
                break;
            case 5:
                printf("Enter Word to Delete: ");
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = '\0'; 
                
                if (root == NULL)
                    printf("Dictionary is empty.\n");
                else {
                    root = deleteNode(root, word);
                    printf("'%s' deleted successfully (if it existed).\n", word);
                }
                break;
            case 6:
                printf("Exiting\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (1);
    
    return 0;
}

