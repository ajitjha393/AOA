#include<bits/stdc++.h>

#define MAX 10
using namespace std;



int V,E; // Vertices and edges

//returns vertex with minimum distance
int min_distance(bool visited[],int dist[])
{
	int min = INT_MAX,min_Index;
	for(int v = 0 ; v < V;v++){
		if(visited[v] == false && dist[v] <= min)
			min = dist[v],min_Index = v;
	}
	return min_Index;
}

void print_path(int parent[],int j)
{
	//BASE CASE SRC VERTEX
	if(parent[j] == -1)
		return;
	print_path(parent,parent[j]);

	cout<< j <<" ";


}

void print_solution(int parent[],int dist[])
{
	int src = 0;
	cout<<"Vertex \t dist \t Path";
	for(int i = 1 ; i < V ; i++)
		{
			cout<<src<<" -> "<<i<<"\t"<<dist[i]<<"\t"<<src;
			print_path(parent,i);
			cout<<endl;
		}

}


void dijkstra(int adj[MAX][MAX],int src)
{
	int parent[MAX],dist[MAX];
	bool visited[MAX];

	//Initialization
	for(int i = 0 ; i < V ;i++)
	{
		parent[i] = -1;
		visited[i] = false;
		dist[i] = INT_MAX;
	}

	dist[src] = 0;

	for(int count = 0 ;count < V-1 ;count++)
	{
		int u = min_distance(visited,dist);
		visited[u] = true;

		for(int v = 0 ; v < V ;v++)
		{
			if(!visited[v] && adj[u][v] != 0 && dist[u] + adj[u][v] < dist[v])
			{
				parent[v] = u;
				dist[v] = dist[u] + adj[u][v];
			}
		}

	}

	print_solution(parent,dist);


}


int main()
{

	 int adj[][MAX] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                       {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
                        {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                        {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
                        {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
                        {0, 0, 4, 0, 10, 0, 2, 0, 0}, 
                        {0, 0, 0, 14, 0, 2, 0, 1, 6}, 
                        {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
                        {0, 0, 2, 0, 0, 0, 6, 7, 0} 
                    }; 
  
  	V = 9;
    dijkstra(adj, 0); 
    return 0; 

}
