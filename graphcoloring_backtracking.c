#include<stdio.h>
void NextValue(int G[][10], int x[], int k, int n, int m)
{
	int j;
	do
	{
		x[k]=(x[k]+1)%(m+1);
		if(x[k]==0)
			return;
		for(j=1;j<=n;j++)
		{
			if(G[k][j]!=0 && x[k]==x[j])
				break;
		}
		if(j==n+1)
			return;
	}while(1);
}
void mColouring(int G[][10], int x[], int k, int n, int m, int *sol)
{
	int i;
	do
	{
		NextValue(G,x,k,n,m);
		if(x[k]==0)
			return;
		if(k==n)
		{
			*sol=*sol+1;
			printf("Solution %d\n",*sol);
			for(i=1;i<=n;i++)
				printf("G[%d]\t",i);
			printf("\n");
			for(i=1; i<=n; i++)
				printf("%d\t",x[i]);
		}
		else
			mColouring(G,x,k+1,n,m,sol);
	}while(1);
}
void main()
{
	int G[10][10], x[10], n,ne,sol=0;
	int m,i,j,u,v;
	printf("Enter number of nodes and edges\n");
	scanf("%d%d",&n,&ne);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			G[i][j]=0;
		x[i]=0;
	}
	for(i=1;i<=ne;i++)
	{
		printf("Enter 1st terminal and 2nd terminal vertex of graph");
		scanf("%d%d",&u,&v);
		if(u>ne || v>ne)
		{
			printf("Invalid vertex");
			i--;
		}
		else
		{
			G[u][v]=1;
			G[v][u]=1;
		}
	}
	printf("Enter no. of coloring avaliable: ");
	scanf("%d",&m);
	mColouring(G,x,1,n,m,&sol);
	printf("Total no. of solution obtained are: %d",sol);
}