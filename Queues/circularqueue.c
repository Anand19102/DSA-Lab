#include <stdio.h>
#include<stdlib.h>     // For exit()
#include <stdbool.h>   // For 'bool' type
#define MAX 10         // Max size. Note: Usable size is MAX-1 = 9

// initilazing queue
int cqueue[MAX];
int rear = 0;
int front = 0;

// Function to check if the cqueue is empty
bool isEmpty() {
    return front == rear ;
}

// Function to check if the cqueue is full
bool isFull() {
    return (rear + 1) % MAX == front;
}

void enqueue() // enqueue
{
    int item;
    if (isFull())
        printf("Queue Overflow \n");
    else
    {
        printf("\nInsert the element in queue : ");
        scanf("%d", &item);
        rear = (rear + 1) % MAX; // Move rear using modulo
        cqueue[rear] = item;      // Insert at the new rear position
    }
}

void dequeue() //dequeue
{
    if(isEmpty())
    {
        printf("\nQueue Underflow \n");
        return ;
    }
    else
    {
        front = (front + 1) % MAX; // Move front using modulo
        printf("\nElement deleted from queue is : %d\n", cqueue[front]);
    }
}

void display()// print queue
{
    int i = (front + 1) % MAX;
    while (i != rear) {
        printf("%d ", cqueue[i]);
        i = (i + 1) % MAX;
    }
    printf("%d ", cqueue[rear]); // Print the last element
}

// Function to peek at the front item
int peek() {
    if (isEmpty()) {
        printf("Queue is empty. Nothing to peek.\n");
        return -1; // Error value
    } else {
        return cqueue[(front + 1) % MAX];
    }
}


int main()
{
int choice;
    while (1)
        {
            printf("\n1.Insert element to queue \n");
            printf("2.Delete element from queue \n");
            printf("3.Display all elements of queue \n");
            printf("4.Peek \n");
            printf("5.Quit \n");
            printf("\nEnter your choice : ");
            scanf("%d", &choice);
            switch (choice)
            {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            int x=peek();
            if(x!=-1) printf("\nfront element is=%d\n",x);
            break;
        case 5:
            exit(1);

        default:

        printf("\nWrong choice \n");

        }

        } 
        return 0;
        }