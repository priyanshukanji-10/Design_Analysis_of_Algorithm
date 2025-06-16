#include<stdio.h>

int parent [10]={0};
void main()
{
	int a,b,u,v,i,j,n,noofedges;
	int visited[10],min,mincost,cost[10][10];

	noofedges=1;
	mincost=0;
	printf("enter the no. of vertix\n");
	scanf("%d",&n);
	printf("enter the adjacency matrix\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		scanf("%d",&cost[i][j]);
		if(cost[i][j]==0)
		cost[i][j]=999;
	}



	printf("the minimum cost edges are\n");
	while(noofedges<n)
	{
		min=999;
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		if(cost[i][j]<min)
		{
			min=cost[i][j];
			a=u=i;
			b=v=j;
		}
		while(parent[u]!=0)
		u=parent[u];
		while(parent[v]!=0)
		v=parent[v];
		if(u!=v)
		{
			noofedges++;
			printf("\nedge(%d->%d)=%d",a,b,min);
			mincost+=min;
			parent[v]=u;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("\nminimum cost=%d",mincost);

}

