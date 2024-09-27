#include<stdio.h>
int main()
{
int n,m1,m2,i,j,t=1;
//printf("Enter the no. of matrices to add (n>=3): ");
//scanf("%d",&n);
printf("Enter the orders of the matrices:");
scanf("%d%d",&m1,&m2);
int sum[m1][m2],ar[m1][m2];
for(i=0;i<m1;i++)
{
for(j=0;j<m2;j++)
{
sum[i][j]=0;
}
}
printf("Enter the elements of the 1st matrix:\n");
while(t==1)
{
if(t!=1)
break;
for(i=0;i<m1;i++)
{
for(j=0;j<m2;j++)
{
scanf("%d",&ar[i][j]);
sum[i][j]+=ar[i][j];
}
}
printf("Enter 1 to enter 1 more matrix: ");
scanf("%d",&t);
}
printf("The added matrix is:\n");
for(i=0;i<m1;i++)
{
for(j=0;j<m2;j++)
{
printf("%d\t",sum[i][j]);
}
printf("\n");
}
return 0;
}
