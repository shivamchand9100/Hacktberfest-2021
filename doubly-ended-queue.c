#include<stdio.h>

void pushback();    //insert at end
void pushfront();   //insert at front
void popback();     //delete form back
void popfront();    //delete from front
void display();
void inputres();    //input restricted
void outputres();   //output restricted

#define size 3
int arr[size];
int front=-1,rear=-1;

int main(){
    int choice;
    
    
    do{
        printf("\n1.Input Restricted\n2.Output Restricted\n3.Display\n");
        printf("Enter your choice of operation:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            inputres();
            break;
            case 2:
            outputres();
            break;
            case 3:
            display();
            break;
            case 4:
            break;
            default:
            printf("Enter valid choice\n");
        }

    }while(choice!=4);
}

void inputres(){
    int choice;
    printf("1.Push back\n2.Pop front\n3.Pop back\n");
    
    do{
        printf("Enter operation:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            pushback();
            break;
            case 2:
            popfront();
            break;
            case 3:
            popback();
            break;
            case 4:
            break;
            default:
            printf("Enter valid choice:\n");
            
        }display();
    }while(choice=!4);
    
}

void outputres(){
    int choice;
    printf("1.Push back\n2.Push front\n3.Pop front\n");
    
    do{
        printf("Enter operation:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            pushback();
            break;
            case 2:
            pushfront();
            break;
            case 3:
            popfront();
            break;
            case 4:
            break;
            default:
            printf("Enter valid choice:\n");
            
        }
    }while(choice=!4);
    display();
}



void pushfront(){
    int item;
    if((rear+1)%size==front){
        printf("Queue is full\n");
        return;
    }
    printf("Enter item: ");
    scanf("%d",&item);
    if(front==-1){
        front=0;
        rear=0;
    }else{
        if(front==0){
            front=size-1;
        }else{
            front-=1;
        }
        
        
    }arr[front]=item;
}

void pushback(){
    int item;
    if((rear+1)%size==front){
        printf("Queue is full\n");
        return;
    }
    printf("Enter item: ");
    scanf("%d",&item);
    if(front==-1){
        front=rear=0;
    }else{
        rear=(rear+1)%size;
    }
    arr[rear]=item;
}

void popfront(){
    
    if(front==-1){
        printf("Queue is empty");
    }else{
        front=(front+1)%size;
    }

}

void popback(){
    if(front==-1){
        printf("Queue is empty");}
    else{
        if(rear==0){
            rear=size-1;
        }else{
            rear-=1;
        }
    }

}

void display(){
    int i;
     if (front==-1)
    {
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in Circular Queue are: ");
    if (rear>=front)
    {
        for (i = front; i <= rear; i++)
            printf("%d ",arr[i]);
    }
    else
    {
        for (i = front; i < size; i++)
            printf("%d ", arr[i]);
 
        for (i = 0; i <= rear; i++)
            printf("%d ", arr[i]);
    }
}
