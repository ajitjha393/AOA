#include<bits/stdc++.h>

using namespace std;


struct Edge{
	
	int src,dest,weight;

};

struct Graph
{
	int V,E;
	struct Edge* edge;

};

struct Graph* createGraph(int V,int E)
{
	struct Graph* myGraph = new Graph;
	myGraph->V = V;
	myGraph->E =E;
	myGraph->edge = new Edge[E];
}


void print_path(int parent[],int j)
{
	if(parent[j] == -1)
		return;
	print_path(parent,parent[j]);
	cout << j << " ";
}

void Bellman(struct Graph* myGraph,int src)
{
	int V = myGraph -> V;
	int E = myGraph -> E;
	int dist[V];
	int parent[V];
	parent[src] = -1;

	for(int i = 0 ; i < V ;i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	for(int i = 1 ;i < V-1 ;i++)
	{
		for(int j = 0 ;j < E;j++)
		{
			int u = myGraph->edge[j].src;
			int v = myGraph->edge[j].dest;
			int weight = myGraph->edge[j].weight;

			//Relaxation
			if(dist[u]!=INT_MAX && dist[u] + weight < dist[v])
			{
				dist[v] = dist[u] + weight;
				parent[v] = u;
			}
		}
	}

	for(int j = 0 ; j < E ; j++)
	{
			int u = myGraph->edge[j].src;
			int v = myGraph->edge[j].dest;
			int weight = myGraph->edge[j].weight;

			//Relaxation
			if(dist[u]!=INT_MAX && dist[u] + weight < dist[v])
			{
				cout <<  "Graph contains negative edge weight cycle : ";
				return;
			}

	}


	//Print path

	for(int i = 0 ;i < V ;i++){
		
		cout <<src<<"  "<<i<<"  "<<dist[i]<<"  "<<src <<"  " ;
		print_path(parent,i);
		cout << endl;
			
	}
	
	

}


int main() 
{ 
    /* Let us create the graph given in above example */
    int V = 5;  // Number of vertices in graph 
    int E = 8;  // Number of edges in graph 
    struct Graph* graph = createGraph(V, E); 
  
    // add edge 0-1 (or A-B in above figure) 
    graph->edge[0].src = 0; 
    graph->edge[0].dest = 1; 
    graph->edge[0].weight = -1; 
  
    // add edge 0-2 (or A-C in above figure) 
    graph->edge[1].src = 0; 
    graph->edge[1].dest = 2; 
    graph->edge[1].weight = 4; 
  
    // add edge 1-2 (or B-C in above figure) 
    graph->edge[2].src = 1; 
    graph->edge[2].dest = 2; 
    graph->edge[2].weight = 3; 
  
    // add edge 1-3 (or B-D in above figure) 
    graph->edge[3].src = 1; 
    graph->edge[3].dest = 3; 
    graph->edge[3].weight = 2; 
  
    // add edge 1-4 (or A-E in above figure) 
    graph->edge[4].src = 1; 
    graph->edge[4].dest = 4; 
    graph->edge[4].weight = 2; 
  
    // add edge 3-2 (or D-C in above figure) 
    graph->edge[5].src = 3; 
    graph->edge[5].dest = 2; 
    graph->edge[5].weight = 5; 
  
    // add edge 3-1 (or D-B in above figure) 
    graph->edge[6].src = 3; 
    graph->edge[6].dest = 1; 
    graph->edge[6].weight = 1; 
  
    // add edge 4-3 (or E-D in above figure) 
    graph->edge[7].src = 4; 
    graph->edge[7].dest = 3; 
    graph->edge[7].weight = -3; 
  
    Bellman(graph, 0); 
  
    return 0; 
} 