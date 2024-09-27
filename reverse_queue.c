#include<stdio.h>
#include<stdlib.h>
struct queue
{
int front;
int rear;
int size;
int *que;
};

struct stack
{
int top;
int size;
int *sta;
};

void push(struct stack *,int);
int pop(struct stack *);

void create_que(struct queue *q)
{
printf("Enter the size of queue: ");
scanf("%d",&q->size);
q->que=(int *)malloc(q->size*sizeof(int));
q->front=q->rear=-1;
}

void create_sta(struct stack *s,struct queue *q)
{
s->size=q->size;
s->sta=(int *)malloc(s->size*sizeof(int));
s->top=-1;
}

void empty(struct queue *q)
{
if(q->front==-1 && q->rear==-1)
{
printf("The queue is empty\n");
}
else
{
printf("The queue is not empty\n");
}
}

void full(struct queue *q)
{
if(q->rear==q->size-1)
{
printf("The queue is full\n");
}
else
{
printf("The queue is not full\n");
}
}

void enqueue(struct queue *q,int e)
{
if(q->rear==q->size-1)
{
printf("Overflow\n");
return;
}
else if(q->rear==-1 && q->rear==-1)
{
q->front=q->rear=0;
q->que[q->rear]=e;
}
else
{
q->rear++;
q->que[q->rear]=e;
}
}

int dequeue(struct queue *q)
{
int e;
if(q->rear==-1 && q->front==-1)
{
printf("Underflow\n");
return 0;
}
else if(q->front==q->rear)
{
e=q->que[q->front];
q->front=q->rear=-1;
}
else
{
e=q->que[q->front];
q->front++;
}
return e;
}

void display(struct queue *q)
{
int i;
for(i=q->front;i<=q->rear;i++)
printf("%d ",q->que[i]);
printf("\n");
}

void reverse(struct queue *q, struct stack *s)
{
int x;
while(q->front!=-1 && q->rear!=-1)
{
x=dequeue(q);
push(s,x);
}
while((q->rear!=q->size-1) || (s->top!=-1))
{
x=pop(s);
enqueue(q,x);
}
}

int main()
{
struct queue q1;
struct stack s1;
create_que(&q1);
create_sta(&s1,&q1);
int ch,c,e;
do
{
printf("1. IsEmpty\n2. IsFull\n3. Enqueue\n4. Dequeue\n5. Display\n6. Reverse\n7. Exit\n");
printf("Enter the choice: ");
scanf("%d",&c);
switch(c)
{
case 1: empty(&q1);
break;

case 2: full(&q1);
break;

case 3:
printf("Enter the element to be enqueued: ");
scanf("%d",&e);
enqueue(&q1,e);
break;

case 4:
e=dequeue(&q1);
if(e)
{
printf("The element dequequed is: %d\n",e);
}
break;

case 5: display(&q1);
break;

case 6:
reverse(&q1,&s1);
printf("The reversed queue is: ");
display(&q1);
break;

case 7: exit(0);
}
printf("Do you wish to continue (0 or 1): ");
scanf("%d",&ch);
}while(ch==1);
}

void push(struct stack *s,int e)
{
s->top++;
s->sta[s->top]=e;
}

int pop(struct stack *s)
{
int e;
e=s->sta[s->top];
s->top--;
return e;
}

