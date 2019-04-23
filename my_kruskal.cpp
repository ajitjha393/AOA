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
	Graph* mygraph = new Graph;
	mygraph->V = V;
	mygraph->E = E;
	mygraph->edge = new Edge[E];
	return mygraph;
};

struct subset{
	int parent;
	int rank;
};

//finds which set does i belongs to
//find and make root as the parent of i 
int find(subset subsets[],int i)
{
	if(subsets[i].parent != i)
		subsets[i].parent = find(subsets,subsets[i].parent);
	return subsets[i].parent;
}

// A function that does union of two sets of x and y 
void Union(subset subsets[],int x,int y)
{
	int xroot = find(subsets,x);
	int yroot = find(subsets,y);

	//Attach smaller rank tree under root of higher rank
	if(subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if(subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent =  xroot;
	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}	 	

}

int myComp(const void* a ,const void* b)
{
	struct Edge* a1 = (struct  Edge*)a;
	struct Edge* b1 = (struct  Edge*)b;
	return a1->weight > b1->weight;
	
}

int kruskal_MST(struct Graph* mygraph)
{
	int V = mygraph->V;
	struct Edge result[V]; //this will store resultant MST
	int e = 0; // index variable for edges
	int i = 0; // index variable for sorted edges

	//sort all edges in non-decreasing order(increasing)

	qsort(mygraph->edge,mygraph->E,sizeof(mygraph->edge[0]),myComp);

	struct subset* subsets = (struct subset*)malloc(V*sizeof(struct subset));

	//V nodes with single element(subset)
	for(int v = 0 ;v < V ;v++)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	while(e < V-1)
	{
		//pick smallest edge and increment;
		struct  Edge next_edge = mygraph->edge[i++];
		int x = find(subsets,next_edge.src);
		int y = find(subsets,next_edge.dest);

		if(x!=y) //nocycle
		{
			result[e++] = next_edge;
			Union(subsets,x,y);

		}


	}

	int totalCost = 0;
	cout << "Following are the edges in the constructed MST : ";
	for(int i = 0 ; i < e ;i++)
		{
			totalCost += result[i].weight; 
			cout <<result[i].src<<"  --->  "<<result[i].dest<<"  =  "<<result[i].weight <<endl;
		}
		return totalCost;
}

int main()
{
	int V,E;
	cout << "Enter the number of vertices and edges of the graph : ";
	cin >> V>>E;
	struct Graph* mygraph = createGraph(V,E);
	for(int i = 0 ; i < E ;i++)
	{
		cout << "Enter src,dest and weigth of the vertex "<<i +1 <<" : ";
		cin >> mygraph->edge[i].src >> mygraph->edge[i].dest >> mygraph->edge[i].weight;
	}

	int totalCost = kruskal_MST(mygraph);
	cout<<"Cost of MST => "<<totalCost<<endl;
	return 0;
}