// dequeue is the same as regular queue, deletion from front
//rear pointer is not needed
//enqueue is modified to insert based on priority //read docs
// Priority Queue using Singly Linked List for Placement Interview Scheduling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    int marks;
    struct Node* next;
};

typedef struct Node Node;

Node* front = NULL;

// Function to create a new node
Node* createNode(char name[], int marks) {
    Node* temp = (Node*)malloc(sizeof(Node));
    strcpy(temp->name, name);
    temp->marks = marks;
    temp->next = NULL;
    return temp;
}

// Function to insert candidate into the priority queue
void insert(char name[], int marks) {
    Node* newNode = createNode(name, marks);

    if (front == NULL || marks > front->marks) {
        newNode->next = front;
        front = newNode;
    } else {
        Node* current = front;
        while (current->next != NULL && current->next->marks >= marks) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    printf("Candidate %s with marks %d added to the queue.\n", name, marks);
}

// Function to schedule interview (delete highest priority)
void scheduleInterview() {
    if (front == NULL) {
        printf("No candidates in the queue.\n");
        return;
    }

    Node* temp = front;
    printf("Interview scheduled for: %s with marks %d\n", temp->name, temp->marks);
    front = front->next;
    free(temp);
}

// Function to display the queue
void displayQueue() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("\nCurrent Interview Queue (Highest Marks First):\n");
    Node* temp = front;
    while (temp != NULL) {
        printf("Name: %-20s Marks: %d\n", temp->name, temp->marks);
        temp = temp->next;
    }
}

// Main menu
int main() {
    int choice, marks;
    char name[50];

    while (1) {
        printf("\n--- Placement Interview Scheduler ---\n");
        printf("1. Insert Candidate\n");
        printf("2. Schedule Interview\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter Candidate Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;  // equal to 0 means removing newline character
                printf("Enter Marks (out of 100): ");
                scanf("%d", &marks);
                insert(name, marks);
                break;

            case 2:
                scheduleInterview();
                break;

            case 3:
                displayQueue();
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

//strcspn is used to remove newline character from fgets input