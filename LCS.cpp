#include<bits/stdc++.h>


using namespace std;

void LCS(string X,string Y)
{

	int m = X.length();
	int n = Y.length();

	int L[m+1][n+1];

	for(int i = 0 ; i <=m ; i++)
	{
		for(int j = 0 ; j <=n ; j++)
		{
			if(i == 0 || j == 0)
				L[i][j] = 0;
			else if(X[i-1] == Y[j-1])
				L[i][j] = L[i-1][j-1] + 1;
			else
				L[i][j] = max(L[i-1][j],L[i][j-1]);

		}
	}

	int lcs = L[m][n];

	string path = "";

	int i = m,j =n; // Start form bottom

	while(i > 0 && j > 0)
	{
		if(X[i-1] == Y[j-1])
		{
			path = X[i-1]+path;
			i--;
			j--; 
		}
		else if(L[i-1][j] > L[i][j-1])
		{
			i--;
		}
		else
		{
			j--;
		}
	}

	cout << "LCS IS => "<<path<<endl;

	cout <<"lcs length => "<<lcs<<endl;
}


int main()
{
	
	string X = "AGGTAB"; 
  string Y = "GXTXAYB"; 
  LCS(X, Y); 
  return 0; 
}