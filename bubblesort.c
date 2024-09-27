#include<stdio.h>
#include<stdbool.h>
void bubble_sort(int[],int);
int main()
{
	int n,arr[20],i;
	scanf("%d",&n);
	printf("Enter the array::");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	bubble_sort(arr,n);
}
void bubble_sort(int arr[],int n)
{
	int i,temp;
	bool flag;
    while(flag==false)
    {
    	flag=true;
    	for(i=0;i<n-1;i++)
    	{
    		if(arr[i]>arr[i+1])
    		{
    			temp=arr[i];
    			arr[i]=arr[i+1];
    			arr[i+1]=temp;
    			flag=false;
			}
		}
	}
		
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
