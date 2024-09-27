#include<stdio.h>
int main()
{
int n=6;
int b=0,ct;
int at[n],bt[n],wt[n],tt[n];
float total=0;
printf("IPSITA ACHARYA\n2005169");
printf("Enter burst time & waiting time of procs:");
for(int i=0;i<n;i++)
{
printf("procs %d:",i+1);
scanf("%d%d",&bt[i],&wt[i]);
}
at[0]=0;
for (int i=1;i<n;i++)
{
at[i]=wt[i]-bt[i-1];
}
for(int i=0;i<n;i++)
{
ct+=bt[i];
tt[i]=ct-at[i];
}
printf("procs at bt wt tat\n");
for (int i=0;i<n;i++)
{
printf("%d %d %d %d %d",i+1,at[i],bt[i],wt[i],tt[i]);
return 0;
}
}
