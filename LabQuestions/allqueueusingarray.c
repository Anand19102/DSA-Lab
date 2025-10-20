#include <stdio.h>
#define SIZE 5

// ------------------ LINEAR QUEUE ------------------
int lqueue[SIZE];
int lfront = -1, lrear = -1;

void enqueueLinear(int value) {
    if (lrear == SIZE - 1) {
        printf("Queue Overflow!\n");
    } else {
        if (lfront == -1)
            lfront = 0;
        lrear++;
        lqueue[lrear] = value;
        printf("%d inserted into Linear Queue.\n", value);
    }
}

void dequeueLinear() {
    if (lfront == -1 || lfront > lrear) {
        printf("Queue Underflow!\n");
    } else {
        printf("%d deleted from Linear Queue.\n", lqueue[lfront]);
        lfront++;
    }
}

void displayLinear() {
    if (lfront == -1 || lfront > lrear) {
        printf("Linear Queue is empty.\n");
    } else {
        printf("Linear Queue elements: ");
        for (int i = lfront; i <= lrear; i++)
            printf("%d ", lqueue[i]);
        printf("\n");
    }
}

// ------------------ DEQUEUE ------------------
int dqueue[SIZE];
int dfront = -1, drear = -1;

void insertFront(int value) {
    if ((dfront == 0 && drear == SIZE - 1) || (dfront == drear + 1)) {
        printf("Dequeue Overflow!\n");
    } else {
        if (dfront == -1)
            dfront = drear = 0;
        else if (dfront == 0)
            dfront = SIZE - 1;
        else
            dfront--;
        dqueue[dfront] = value;
        printf("%d inserted at front of Dequeue.\n", value);
    }
}

void insertRear(int value) {
    if ((dfront == 0 && drear == SIZE - 1) || (dfront == drear + 1)) {
        printf("Dequeue Overflow!\n");
    } else {
        if (dfront == -1)
            dfront = drear = 0;
        else if (drear == SIZE - 1)
            drear = 0;
        else
            drear++;
        dqueue[drear] = value;
        printf("%d inserted at rear of Dequeue.\n", value);
    }
}

void deleteFront() {
    if (dfront == -1) {
        printf("Dequeue Underflow!\n");
    } else {
        printf("%d deleted from front of Dequeue.\n", dqueue[dfront]);
        if (dfront == drear)
            dfront = drear = -1;
        else if (dfront == SIZE - 1)
            dfront = 0;
        else
            dfront++;
    }
}

void deleteRear() {
    if (dfront == -1) {
        printf("Dequeue Underflow!\n");
    } else {
        printf("%d deleted from rear of Dequeue.\n", dqueue[drear]);
        if (dfront == drear)
            dfront = drear = -1;
        else if (drear == 0)
            drear = SIZE - 1;
        else
            drear--;
    }
}

void displayDequeue() {
    if (dfront == -1) {
        printf("Dequeue is empty.\n");
    } else {
        printf("Dequeue elements: ");
        int i = dfront;
        while (1) {
            printf("%d ", dqueue[i]);
            if (i == drear) break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

// ------------------ CIRCULAR QUEUE ------------------
int cqueue[SIZE];
int cfront = -1, crear = -1;

void enqueueCircular(int value) {
    if ((crear + 1) % SIZE == cfront) {
        printf("Circular Queue Overflow!\n");
    } else {
        if (cfront == -1)
            cfront = 0;
        crear = (crear + 1) % SIZE;
        cqueue[crear] = value;
        printf("%d inserted into Circular Queue.\n", value);
    }
}

void dequeueCircular() {
    if (cfront == -1) {
        printf("Circular Queue Underflow!\n");
    } else {
        printf("%d deleted from Circular Queue.\n", cqueue[cfront]);
        if (cfront == crear)
            cfront = crear = -1;
        else
            cfront = (cfront + 1) % SIZE;
    }
}

void displayCircular() {
    if (cfront == -1) {
        printf("Circular Queue is empty.\n");
    } else {
        printf("Circular Queue elements: ");
        int i = cfront;
        while (1) {
            printf("%d ", cqueue[i]);
            if (i == crear) break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

// ------------------ MAIN MENU ------------------
int main() {
    int choice, subchoice, value;

    while (1) {
        printf("\n================= MAIN MENU =================\n");
        printf("1. Linear Queue\n");
        printf("2. Dequeue (Double Ended Queue)\n");
        printf("3. Circular Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n--- Linear Queue Operations ---\n");
                printf("1. Enqueue\n2. Dequeue\n3. Display\n");
                printf("Enter your choice: ");
                scanf("%d", &subchoice);
                switch (subchoice) {
                    case 1:
                        printf("Enter value: ");
                        scanf("%d", &value);
                        enqueueLinear(value);
                        break;
                    case 2:
                        dequeueLinear();
                        break;
                    case 3:
                        displayLinear();
                        break;
                    default:
                        printf("Invalid choice!\n");
                }
                break;

            case 2:
                printf("\n--- Dequeue Operations ---\n");
                printf("1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n");
                printf("Enter your choice: ");
                scanf("%d", &subchoice);
                switch (subchoice) {
                    case 1:
                        printf("Enter value: ");
                        scanf("%d", &value);
                        insertFront(value);
                        break;
                    case 2:
                        printf("Enter value: ");
                        scanf("%d", &value);
                        insertRear(value);
                        break;
                    case 3:
                        deleteFront();
                        break;
                    case 4:
                        deleteRear();
                        break;
                    case 5:
                        displayDequeue();
                        break;
                    default:
                        printf("Invalid choice!\n");
                }
                break;

            case 3:
                printf("\n--- Circular Queue Operations ---\n");
                printf("1. Enqueue\n2. Dequeue\n3. Display\n");
                printf("Enter your choice: ");
                scanf("%d", &subchoice);
                switch (subchoice) {
                    case 1:
                        printf("Enter value: ");
                        scanf("%d", &value);
                        enqueueCircular(value);
                        break;
                    case 2:
                        dequeueCircular();
                        break;
                    case 3:
                        displayCircular();
                        break;
                    default:
                        printf("Invalid choice!\n");
                }
                break;

            case 4:
                printf("Exiting program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
