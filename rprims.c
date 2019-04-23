#include<stdio.h>
#include<stdlib.h>
#define INF 99
#define MAX 20
int N;

void prims(int a[N][N],int start)
{
	int prev[MAX],dist[MAX],i,j;
	int selected[MAX];
	for(i=0;i<N;i++)
	{
	   selected[i]=0;
	}
	int count=1;
	for(i=0;i<N;i++)
	{
		dist[i]=INF;
	}

	dist[start]=0;
	selected[start]=1;
	//prev[start] = -1;
	while(count<N)
	{
		for(i=0;i<N;i++)
		{
			if((dist[i]>a[start][i]) && !selected[i])
			{
				dist[i]=a[start][i];
				prev[i]=start;
			}
		}
		int min = INF;
		int m = start;
		for(i=0;i<N;i++)
		{
			if(!selected[i] && min>dist[i])
			{
				min=dist[i];
				m=i;
			}
		}
		start = m;
		selected[start]=1;
		count ++;
	}
	
	for(i=0;i<N;i++)
	{
	    printf("%c\t%c\t%d\n",i+65,prev[i]+65,dist[i]);
	}    
}

void main()
{
	int i,j,Graph[MAX][MAX];
	printf("Enter the number of vertices\n");
	scanf("%d",&N);
	printf("Enter the adjacency matrix\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%d",&Graph[i][j]);
		}
	}

	// for(i= 0 ; i < N ;i++)
	// {	for(j = 0 ; j <N ;j++)
	// 	{
	// 		printf("%d ",Graph[i][j]);
	// 	}
	// printf("\n");	
	// }
	// for(j=0;j<N;j++)
	// {
	// 	for(j=0;j<N;j++)
	// 	{
	// 		if( i!=j && Graph[i][j]==0 )
	// 		{
	// 			Graph[i][j]=INF;
	// 		}
	// 	}
	// }
	
	// N = 4;
    // int Graph[4][4] = {
    // {0, 5, 15, 30},
    // {5, 0, 10, 99},
    // {15,10,0,20},
    // {30,99,20,0}
    // };

	prims(Graph,0);
}
	