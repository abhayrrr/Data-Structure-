#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void create() {
    struct node *newnode, *temp;
    int choice = 1;

    while (choice) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->prev = newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
            newnode->prev = temp;
        }

        printf("Continue (1/0): ");
        scanf("%d", &choice);
    }
}

void insertLeft() {
    struct node *newnode, *temp;
    int key;

    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        printf("Enter value to insert: ");
        scanf("%d", &newnode->data);
        printf("Insert to left of which value: ");
        scanf("%d", &key);

        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = newnode->prev = NULL;

        temp = head;
        while (temp != NULL && temp->data != key)
            temp = temp->next;

        if (temp == NULL) {
            printf("Value not found.\n");
            free(newnode);
        } else if (temp == head) {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        } else {
            newnode->next = temp;
            newnode->prev = temp->prev;
            temp->prev->next = newnode;
            temp->prev = newnode;
        }
    }
}

void deleteValue() {
    struct node *temp;
    int key;

    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        printf("Enter value to delete: ");
        scanf("%d", &key);

        temp = head;
        while (temp != NULL && temp->data != key)
            temp = temp->next;

        if (temp == NULL) {
            printf("Value not found.\n");
        } else if (temp == head) {
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            free(temp);
            printf("Node deleted.\n");
        } else {
            temp->prev->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            free(temp);
            printf("Node deleted.\n");
        }
    }
}

void display() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
    } else {
        printf("Doubly linked list:\n");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1.Create\n2.Insert Left\n3.Delete by Value\n4.Display\n5.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                insertLeft();
                break;
            case 3:
                deleteValue();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}
