#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int x) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void insertBeg(struct node** start, int x) {
    struct node* newNode = createNode(x);
    newNode->next = *start;
    *start = newNode;
}

void insertEnd(struct node** start, int x) {
    struct node* newNode = createNode(x);
    if (*start == NULL) {
        *start = newNode;
        return;
    }

    struct node* temp = *start;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayList(struct node* start) {
    struct node* temp = start;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}



void insertAtPosition(struct Node** head, int data, int position) {
    struct node* newnode = createnode(data);

    if (position == 1) {
        newnode->next = *head;
        *head = newnode;
        return;
    }

    struct node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;


int main() {
    struct node* head = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Display List\n");
        printf("4. Insert at Position\n");

        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertBeg(&head, value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;
            case 3:
                printf("Linked List: ");
                displayList(head);
                break;
            case 4:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(&head, value, position);
                break;

            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
