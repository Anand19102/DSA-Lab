#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for doubly linked list
struct Node {
    char url[100];
    struct Node *prev;
    struct Node *next;
};

struct Node *current = NULL;

// Function to create a new node
struct Node* createNode(char *url) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->url, url);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Visit a new web page
void visitPage(char *url) {
    struct Node *newNode = createNode(url);

    if (current == NULL) {
        current = newNode;
    } else {
        // Remove forward history if it exists
        struct Node *temp = current->next;
        while (temp != NULL) {
            struct Node *toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    printf("Visited: %s\n", current->url);
}

// Go backward in history
void goBack() {
    if (current == NULL || current->prev == NULL) {
        printf("No previous page!\n");
        return;
    }
    current = current->prev;
    printf("Moved Back to: %s\n", current->url);
}

// Go forward in history
void goForward() {
    if (current == NULL || current->next == NULL) {
        printf("No forward page!\n");
        return;
    }
    current = current->next;
    printf("Moved Forward to: %s\n", current->url);
}

// Display the browsing history
void displayHistory() {
    if (current == NULL) {
        printf("No browsing history!\n");
        return;
    }

    struct Node *temp = current;
    while (temp->prev != NULL)
        temp = temp->prev;

    printf("\nBrowsing History:\n");
    while (temp != NULL) {
        if (temp == current)
            printf("-> %s (Current Page)\n", temp->url);
        else
            printf("   %s\n", temp->url);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;
    char url[100];

    while (1) {
        printf("\n--- Web Browser Navigation ---\n");
        printf("1. Visit New Page\n");
        printf("2. Back\n");
        printf("3. Forward\n");
        printf("4. Show History\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                scanf("%s", url);
                visitPage(url);
                break;
            case 2:
                goBack();
                break;
            case 3:
                goForward();
                break;
            case 4:
                displayHistory();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
