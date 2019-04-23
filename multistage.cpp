#include<bits/stdc++.h>
#define MAX 10
#define INF INT_MAX
//ASSUME NO PATH AS 0

using namespace std;

void print_path(int parent[],int j)
{
	if(parent[j] == -1)
		return;
	print_path(parent,parent[j]);
	cout <<j<<" ";
}

int multistage(int adj[][MAX],int N)
{
	int dist[MAX];
	int parent[MAX];
	parent[N-1] = -1;
	dist[N-1] = 0; // dest vertex cost 0;

	for(int i = N-2 ;i >= 0 ;i--)
	{
		dist[i] = INF;
		for(int j = i ; j < N ;j++)
		{
			  if (adj[i][j] == INF) // Reject 
                continue;

              //dist[i] = min(dist[i],adj[i][j]+dist[j]);

              if(dist[i] > (adj[i][j] + dist[j]))
              {
              	dist[i] = adj[i][j] + dist[j];
              	parent[i] = j;
              }
              else {
              	parent[i] = i;
              }   
		}
	}
	cout<<N-1<<" ";
	print_path(parent,0);

return dist[0];

}

int main() 
{ 
    // Graph stored in the form of an 
    // adjacency Matrix 
    int adj[][MAX] = 
      {{INF, 1, 2, 5,INF, INF, INF, INF}, 
       {INF, INF, INF, INF, 4, 11, INF, INF}, 
       {INF, INF, INF, INF, 9, 5, 16,INF}, 
       {INF, INF, INF, INF, INF, INF, 2, INF}, 
       {INF, INF, INF, INF, INF, INF,INF, 18}, 
       {INF, INF, INF, INF, INF, INF,INF, 13}, 
       {INF, INF, INF, INF, INF, INF,INF,2}}; 
  
  int cost = multistage(adj,8);
    cout<<endl << cost; 
    return 0; 
} 

