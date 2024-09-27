#include<stdlib.h>
#include<stdio.h>

typedef struct node{
    int data;
    struct node *next;
}*NODE;
NODE start=NULL;
//NODE end=NULL;

void create(){
    NODE newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    int n;
    printf("\n\n__Enter -1 to exit__\n");

    do{
        printf("Enter element= ");
        scanf("%d",&n);
        if(n==-1){
            break;
        }
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=n;
        if(start==NULL){
            start=newnode;
            newnode->next=start;
        }
        else{
            newnode->next=start;
            start=newnode;
        }
        
    }while(n!=-1);
    
}

void display(){ 
      
    NODE temp;
    temp=start;
    printf("\nDisplaying \n");

    if (start == NULL)
        printf("\nList is empty\n");
    else {
            do{
                printf("%d",temp->data);
                temp=temp->next;
            }while(temp!=start);

            printf("\n");
        }

   
}








int main()
{
    NODE start=(struct node*)malloc(sizeof(struct node));
    int flag=1;
    int choice;
    while(flag==1){
    printf("\nOperations on circular linked list\n");
    printf("Press 0: To exit\nPress 1: Create\nPress 2: Display\nPress 3: Search\nPress 4: Insert data at the end\nPress 5: Insert after any given data\nPress 6: Delete any given data\nPress 7: Delete any given node number\n\n*/");
    printf("***************************\nEnter Choice: ");
    scanf("%d",&choice);
    if(choice==0){
        flag==0;
        break;
    }
    
    switch (choice)
    {   
    case 1:
        create();
        break;
    case 2:
        display();
        break;
    /*case 3:
        search();
        break;
    case 4:
        insertatend();
        break;
    case 5:
        insertatposi();
        break;
    case 6:
        deletedata();
        break;    
    case 7:
        deletenode();
        break;

    default:
        printf("Please enter a valid input");
    }*/

    }    
}
}
