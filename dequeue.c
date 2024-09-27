#include<stdio.h>
#include<stdlib.h>
struct queue
{
int data;
struct queue *next;
struct queue *prev;
}*front=NULL,*rear=NULL;

void empty()
{
if(front==NULL || rear==NULL)
{
printf("The queue is empty\n");
}
else
{
printf("The queue is not empty\n");
}
}

void full()
{
struct queue *t;
t=(struct queue *)malloc(sizeof(struct queue));
if(t==NULL)
{
printf("The queue is full\n");
}
else
{
printf("The queue is not full\n");
}
}

void insert_front(int x)
{
struct queue *new;
new=(struct queue *)malloc(sizeof(struct queue));
if(new==NULL)
{
printf("Overflow\n");
return;
}
new->data=x;
new->next=NULL;
new->prev=NULL;
if(front==NULL && rear==NULL)
{
front=rear=new;
}
else
{
new->next=front;
front->prev=new;
front=new;
}
}

void insert_rear(int x)
{
struct queue *new;
new=(struct queue *)malloc(sizeof(struct queue));
new->data=x;
new->next=NULL;
new->prev=NULL;
if(new==NULL)
{
printf("Overflow\n");
return;
}
if(front==NULL && rear==NULL)
{
front=rear=new;
}
else
{
rear->next=new;
new->prev=rear;
rear=new;
}
}

int delete_front()
{
int x;
if(front==NULL)
{
printf("Underflow\n");
return 0;
}
x=front->data;
if(front->next==NULL)
{
free(front);
rear=front=NULL;
return x;
}
front=front->next;
free(front->prev);
front->prev=NULL;
return x;
}

int delete_rear()
{
int x;
if(rear==NULL)
{
printf("Underflow\n");
return 0;
}
x=rear->data;
if(rear->prev==NULL)
{
free(rear);
front=rear=NULL;
return x;
}
rear=rear->prev;
free(rear->next);
rear->next=NULL;
return x;
}

void display()
{
if(front==NULL)
{
printf("The queue is empty\n");
return;
}
struct queue *t;
t=front;
printf("The queue is: ");
while(t)
{
printf("%d ",t->data);
t=t->next;
}
printf("\n");
}

void input_restrict()
{
int c,x;
do
{
printf("1. IsEmpty\n2. IsFull\n3. Insert from rear\n4. Delete from front\n5. Delete from rear\n6. Display\n7. Exit\n");
printf("Enter the choice: ");
scanf("%d",&c);
switch(c)
{
case 1: empty();
break;

case 2: full();
break;

case 3:
printf("Enter the element to be enqueued: ");
scanf("%d",&x);
insert_rear(x);
break;

case 4:
x=delete_front();
if(x)
printf("The element dequeued is: %d\n",x);
break;

case 5:
x=delete_rear();
if(x)
{
printf("The Element Dequeued is:- %d\n",x);
}
break;

case 6: display();
break;

case 7: exit(0);
}
printf("Enter the choice (0 or 1): ");
scanf("%d",&c);
}while(c==1);
}

void output_restrict()
{
int c,x;
do
{
printf("1. IsEmpty\n2. IsFull\n3. Insert from rear\n4. Insert from front\n5. Delete from front\n6. Display\n7. Exit\n");
printf("Enter the choice: ");
scanf("%d",&c);
switch(c)
{
case 1: empty();
break;

case 2: full();
break;

case 3:
printf("Enter the element to be enqueued: ");
scanf("%d",&x);
insert_rear(x);
break;

case 4:
printf("Enter the element to be enqueued: ");
scanf("%d",&x);
insert_front(x);
break;

case 5:
x=delete_front();
if(x)
{
printf("The element dequeued is: %d\n",x);
}
break;

case 6: display();
break;

case 7: exit(0);
}
printf("Enter the choice (0 or 1): ");
scanf("%d",&c);
}while(c==1);
}

int main()
{
int c;
printf("1. Create input restricted queue\n2. Create output restricted queue\n");
printf("Enter the choice: ");
scanf("%d",&c);
if(c==1)
{
input_restrict();
}
else
{
output_restrict();
}
return 0;
}

