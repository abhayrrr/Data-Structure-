#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
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
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }

        printf("Do you want to continue (1/0): ");
        scanf("%d", &choice);
    }
}

void deleteFirst() {
    struct node *temp;
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        temp = head;
        head = head->next;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
    }
}

void deleteLast() {
    struct node *temp, *prev;
    if (head == NULL) {
        printf("List is empty.\n");
    } else if (head->next == NULL) {
        printf("Deleted element: %d\n", head->data);
        free(head);
        head = NULL;
    } else {
        temp = head;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
    }
}

void deleteSpecified() {
    struct node *temp, *prev;
    int key;

    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        printf("Enter element to delete: ");
        scanf("%d", &key);

        if (head->data == key) {
            temp = head;
            head = head->next;
            printf("Deleted element: %d\n", temp->data);
            free(temp);
        } else {
            temp = head;
            while (temp != NULL && temp->data != key) {
                prev = temp;
                temp = temp->next;
            }

            if (temp == NULL) {
                printf("Element not found.\n");
            } else {
                prev->next = temp->next;
                printf("Deleted element: %d\n", temp->data);
                free(temp);
            }
        }
    }
}

void display() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        temp = head;
        printf("Linked list elements:\n");
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Create\n2. Delete First\n3. Delete Specified\n4. Delete Last\n5. Display\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;

            case 2:
                deleteFirst();
                break;

            case 3:
                deleteSpecified();
                break;

            case 4:
                deleteLast();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}
