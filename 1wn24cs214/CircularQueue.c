#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

void insert() {
    int item;
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Queue Overflow! Cannot insert element.\n");
    } else {
        printf("Enter element to insert: ");
        scanf("%d", &item);

        if (front == -1) {
            front = rear = 0;
        } else if (rear == MAX - 1) {
            rear = 0;
        } else {
            rear++;
        }

        cq[rear] = item;
        printf("%d inserted into queue.\n", item);
    }
}

void delete() {
    if (front == -1) {
        printf("Queue is empty! Cannot delete element.\n");
    } else {
        printf("%d deleted from queue.\n", cq[front]);

        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX - 1) {
            front = 0;
        } else {
            front++;
        }
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are:\n");

        if (front <= rear) {
            for (i = front; i <= rear; i++)
                printf("%d\n", cq[i]);
        } else {
            for (i = front; i < MAX; i++)
                printf("%d\n", cq[i]);
            for (i = 0; i <= rear; i++)
                printf("%d\n", cq[i]);
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}
