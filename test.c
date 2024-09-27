// menu driven program to implement queue operations using static array
#include <stdio.h>
#include <stdlib.h>

int queue_arr[15];
int rear = -1;
int front = -1;

void insert(int item);
int del();
int peek();
void display();
int isFull();
int isEmpty();

int main()
{
    int choice, item;
    while (1)
    {
        printf("\n1.Insert\n");
        printf("2.Delete\n");
        printf("3.Check if queue is empty\n");
        printf("4.Check if queue is full\n");
        printf("5.Display element at the front\n");
        printf("6.Display all elements of the queue\n");
        printf("7.Quit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nInput the element for adding in queue : ");
            scanf("%d", &item);
            insert(item);
            break;
        case 2:
            item = del();
            printf("\nDeleted element is  %d\n", item);
            break;
        case 3:
            if (isEmpty())
            {
                printf("\nQueue is empty\n");
            }
            else
            {
                printf("Queue is not empty");
            }
            break;
        case 4:
            if (isFull())
            {
                printf("\nQueue is full\n");
            }
            else
            {
                printf("Queue is not full");
            }
            break;
        case 5:
            printf("\nElement at the front is %d\n", peek());
            break;
        case 6:
            display();
            break;
        case 7:
            exit(1);
        default:
            printf("\nPlease Enter a Valid choice\n");
        }
    }

    return 0;
}

void insert(int item)
{
    if (isFull())
    {
        printf("\nQueue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear = rear + 1;
    queue_arr[rear] = item;
}

int del()
{
    int item;
    if (isEmpty())
    {
        printf("\nQueue Underflow\n");
        exit(1);
    }
    item = queue_arr[front];
    front = front + 1;
    return item;
}

int peek()
{
    if (isEmpty())
    {
        printf("\nQueue Underflow\n");
        exit(1);
    }
    return queue_arr[front];
}

int isEmpty()
{
    if (front == -1 || front == rear + 1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (rear == 15 - 1)
        return 1;
    else
        return 0;
}

void display()
{
    int i;
    if (isEmpty())
    {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nQueue is :\n\n");
    for (i = front; i <= rear; i++)
        printf("%d  ", queue_arr[i]);
    printf("\n\n");
}
