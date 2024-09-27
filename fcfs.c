#include<stdio.h>
void WT(int procs[], int n, int bt[], int wt[])
{
wt[0] = 0;
for (int i = 1; i < n ; i++ )
wt[i] = bt[i-1] + wt[i-1] ;
}
void TAT( int procs[], int n, int bt[], int wt[], int tat[])
{
for (int i = 0; i < n ; i++)
tat[i] = bt[i] + wt[i];
}
void AVGT( int procs[], int n, int bt[])
{
int wt[n], tat[n], totwt = 0, tottat = 0;
WT(procs, n, bt, wt);
TAT(procs, n, bt, wt, tat);
printf("Procs BT WT TAT\n");
for (int i=0; i<n; i++)
{
totwt = totwt + wt[i];
tottat = tottat + tat[i];
printf("   %d ",(i+1));
printf(" %d ", bt[i] );
printf(" %d ",wt[i] );
printf(" %d\n",tat[i] );
}
float s=(float)totwt / (float)n;
float t=(float)tottat / (float)n;
printf("Average waiting time = %d",s);
printf("\n");
printf("Average turn around time = %d ",t);
}
int main()
{
int procs[] = { 1, 2, 3};
int n = sizeof procs / sizeof procs[0];
int bt[] = {2, 4, 6};
AVGT(procs, n, bt);
printf("\n");
return 0;
}
