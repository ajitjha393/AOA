//Time complexity O(nlogn) // Same as sorting;

#include<bits/stdc++.h>

using namespace std;

void find_Optimal_Storage(int L[],int n) // L -> length of the each program,n total number of programs
{
	sort(L,L+n);

	//print order

	cout << "The optimal order for minimum MRT => " ;
	for(int i = 0 ; i < n ;i++)
		cout<<L[i]<<" ";
	cout << endl;

	//MRT
	double MRT = 0.0;
	for(int i = 0 ; i < n ;i++)
	{
		int sum  = 0;
		for(int j = 0 ; j <= i ; j++)
			sum += L[j];
		MRT += sum;
	}
	MRT /=n;
	cout << "MRT = "<<MRT<<endl;
}



int main()
{
	int L[] = {2,5,4};
	int n = 3; 
	find_Optimal_Storage(L,n);
	return 0;
	
}