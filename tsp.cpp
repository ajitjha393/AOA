//USING TOP DOWN DP

#include<bits/stdc++.h>

using namespace std;



#define n  4 // No of nodes(Cities)

//Adjacency Matrix for graph

int dist[4][4] = {
		{0,1,15,6},
		{2,0,7,3},
		{9,6,0,12},
		{10,4,8,0}

};

int parent[n][1<<n];
// parent[0][1] = -1;

//If all Cities has been visited

int VISITED_ALL = (1 << n) -1; //2^n - 1

int dp[1<<4][4]; //2^n * n

int tsp(int mask,int pos) 							//Pos is position of current node
{
	//BASE CASE
	if(mask == VISITED_ALL)
		return dist[pos][0];                        //Assuming first node is the starting vertex

	//Lookup table
	if(dp[mask][pos] != -1)
		return dp[mask][pos];

	int ans = INT_MAX;

	// Try to go to unvisited city
	for (int city = 0; city < n; ++city)
	{
		if((mask & (1 << city)) == 0){

		int newAns = dist[pos][city] + tsp(mask | (1 << city),city);
		// ans = min(ans,newAns);
		
		if(ans > newAns){
			ans = newAns;
			parent[pos][mask] = city;
		}
	}
	else{
		parent[pos][(1<<n) - 1] = -1;
	}

}
return dp[mask][pos] = ans;

}

void printpath()
{
	
    int path[n];
	int count = 0;
	int cur_node = 0;
	int cur_mask = 1;
	do{
		path[count++] = cur_node;
		cur_node = parent[cur_node][cur_mask];
		cur_mask = cur_mask | (1 << cur_node);
		cout << path[count-1] <<endl;
	}while(cur_node != -1);
	int x;
	// for(int i  = 0 ; i < count ; i++)
	// {
	// 	cout << path[i] <<" ";
	// 	cin>>x;
	// }
	cout << endl;
}


int main()
{
	for (int i = 0; i < (1<<n); ++i)
	{
		for(int j = 0 ; j < n ; j++){
			dp[i][j] = -1;

		}

	}

	// parent[0][1] = -1;
	cout << tsp(1,0)<<endl;
	printpath();
	return 0;
		
	
}