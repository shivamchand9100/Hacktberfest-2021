//Program To Sort
//By Name
//By DOB
//By Date Of Joining
//By Salary

#include<stdio.h>
#include<string.h>
struct date
{
    int day;
    int month;
    int year;
};
struct employee
{
    char name[20];
    struct date dob;
    struct date doj;
    float salary;

};
void getdata(struct employee list[70],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Enter details of Employee %d",i+1);
        printf("\nEnter Name :");
        scanf("%s",list[i].name);
        printf("\nEnter DOB in dd/mm/yy :");
        scanf("%d%d%d",&list[i].dob.day,&list[i].dob.month,&list[i].dob.year);
        printf("\nEnter date of joining in dd/mm/yy :");
        scanf("%d%d%d",&list[i].doj.day,&list[i].doj.month,&list[i].doj.year);
        printf("\nEnter salary :");
        scanf("%f",&list[i].salary);
    }
}
void showdata(struct employee list[70],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("\nEmployee No.: %d ",i+1);
        printf("Name :%s",list[i].name);
        printf("\nDOB :%d:%d:%d",list[i].dob.day,list[i].dob.month,list[i].dob.year);
        printf("\nDate Of Joining :%d:%d:%d",list[i].doj.day,list[i].doj.month,list[i].doj.year);
        printf("\nSalary :%f",list[i].salary);
    }
}
void swap(struct employee list[70],int i,int j)
{
    struct employee temp;
    temp=list[i];
    list[i]=list[j];
    list[j]=temp;
}
void sortName(struct employee list[70],int n)
{
   for(int i=0;i<n;i++)
   {
    for(int j=i+1;j<n;j++)
    {
        if(strcmp(list[i].name,list[j].name)>0)
        {
            swap(list,i,j);
        }
    }
   }
   showdata(list,n);
}
void sortDBirth(struct employee list[70],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(list[i].dob.year>list[j].dob.year)
            {swap(list,i,j);}
            else if(list[i].dob.year==list[j].dob.year)
            {
                if(list[i].dob.month>list[j].dob.month)
                {
                    swap(list,i,j);
                }
                else if (list[i].dob.month==list[j].dob.month)
                {
                    if(list[i].dob.day>list[j].dob.day)
                    {
                        swap(list,i,j);
                    }
                }
            }
        }
    }
    showdata(list,n);
}
void sortDJoin(struct employee list[70],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(list[i].doj.year>list[j].doj.year)
            {
                 swap(list,i,j);
            }
            else if(list[i].doj.year==list[j].doj.year)
            {
                if(list[i].doj.month>list[j].doj.month)
                {
                    swap(list,i,j);
                }
                else if(list[i].doj.month==list[j].doj.month)
                {
                    if(list[i].doj.day>list[j].doj.day)
                    {
                        swap(list,i,j);
                    }
                }
            }
        }
    }
    showdata(list,n);
}
void sortsal(struct employee list[70],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(list[i].salary>list[j].salary)
            {
                swap(list,i,j);
            }
        }
    }
    showdata(list,n);
}
int main()
{
    int n,choice;
    printf("Enter number of employee :");
    scanf("%d",&n);
    struct employee data[n];   
    printf("\n1. Sort By Name.\n2. Sort By Date of birth.\n3. Sort By Data Of Joining.\n4. Sort By Salary.\n");
    printf("\nSelect Operation To Perform :\n");
    scanf("%d",&choice);
    getdata(data,n);
    switch(choice)
    {
    case 1:
         printf("\nEmployee data sorted by name :\n");
         sortName(data,n);
         break;
    case 2:
         printf("\nEmployee data sorted by  DOB :\n");
         sortDBirth(data,n);
         break;
    case 3:
         printf("\nEmployee data sorted by DOJ :\n");
         sortDJoin(data,n);
         break;
    case 4:
         printf("\nEmployee data sorted by salary :\n");
         sortsal(data,n);
         break;
    default:
         printf("\nInvalid Input!");
    }
    return 0;
}
