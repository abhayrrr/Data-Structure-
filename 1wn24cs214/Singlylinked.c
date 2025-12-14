#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head1 = NULL, *head2 = NULL;

struct node* create(struct node *head) {
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

        printf("Continue (1/0): ");
        scanf("%d", &choice);
    }
    return head;
}

void display(struct node *head) {
    struct node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
    } else {
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

struct node* sort(struct node *head) {
    struct node *i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    return head;
}

struct node* reverse(struct node *head) {
    struct node *prev = NULL, *curr = head, *next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct node* concatenate(struct node *head1, struct node *head2) {
    struct node *temp;
    if (head1 == NULL)
        return head2;
    temp = head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    return head1;
}

int main() {
    int choice;

    while (1) {
        printf("\n1.Create List1\n2.Create List2\n3.Display List1\n4.Sort List1\n5.Reverse List1\n6.Concatenate\n7.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head1 = create(head1);
                break;
            case 2:
                head2 = create(head2);
                break;
            case 3:
                display(head1);
                break;
            case 4:
                head1 = sort(head1);
                printf("List sorted.\n");
                break;
            case 5:
                head1 = reverse(head1);
                printf("List reversed.\n");
                break;
            case 6:
                head1 = concatenate(head1, head2);
                printf("Lists concatenated.\n");
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}
