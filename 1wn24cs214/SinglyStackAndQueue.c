#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;
struct node *front = NULL, *rear = NULL;

void push() {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter element: ");
    scanf("%d", &newnode->data);
    newnode->next = top;
    top = newnode;
    printf("Pushed successfully.\n");
}

void pop() {
    struct node *temp;
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        temp = top;
        top = top->next;
        printf("Popped element: %d\n", temp->data);
        free(temp);
    }
}

void displayStack() {
    struct node *temp = top;
    if (temp == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements:\n");
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

void enqueue() {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter element: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
    printf("Inserted successfully.\n");
}

void dequeue() {
    struct node *temp;
    if (front == NULL) {
        printf("Queue is empty.\n");
    } else {
        temp = front;
        front = front->next;
        printf("Deleted element: %d\n", temp->data);
        free(temp);

        if (front == NULL)
            rear = NULL;
    }
}

void displayQueue() {
    struct node *temp = front;
    if (temp == NULL) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements:\n");
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1.Push(Stack)\n2.Pop(Stack)\n3.Display Stack\n4.Enqueue(Queue)\n5.Dequeue(Queue)\n6.Display Queue\n7.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                displayStack();
                break;
            case 4:
                enqueue();
                break;
            case 5:
                dequeue();
                break;
            case 6:
                displayQueue();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}
