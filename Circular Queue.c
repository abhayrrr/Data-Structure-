#include <stdio.h>
#define size 5

int queue[size];
int front = -1;
int rear = -1;

//insertion

void insert(int x) {
    if(front == -1 && rear == -1) {
            front = rear = 0;
            queue[rear] = x;
    }
    else if((rear+1)% size == front) {
        printf("Queue overflow!");
    }
    else {
        rear = (rear+1) % size;
        queue[rear] = x;
        printf("%d is inserted!", x);
    }
}

//delete
void delete() {
    if(front == -1 && rear == -1) {
        printf("Queue underflow!");
    }
    else {
        printf("Deleted elements are : %d \n", queue[front]);
        if(front == rear) {
                front = rear = -1;
    }
    else {
        front = (front+1) % size;
    }
    }
}

//display

void display() {
    int i = front;
    if(front == -1 && rear == -1) {
            printf("Queue underflow!");
    }
    else {
            printf("Queue elements are : \n");
    while(i !=rear) {
            printf("%d \n", queue[i]);
            i = (i+1) % size;
        }
        printf("%d \n", queue[rear]);
        }
    }


    int main() {
        int choice, value;
        while(1) {
                printf("////////////MENU//////// \n");
                printf("1.insert \n");
                printf("2.delete \n");
                printf("3.display \n");
                printf("4.exit \n");
                scanf("%d", &choice);

                switch(choice) {
                case 1:
                    printf("Enter value to insert :");
                    scanf("%d", &value);
                    insert(value);
                    break;

                case 2:
                    delete();
                    break;

                case 3:
                    display();
                    break;

                case 4:
                    printf("Exit");
                    return 0;

                case 5:
                    printf("Invalid choice");


                    return 0;
                }
        }
    }
