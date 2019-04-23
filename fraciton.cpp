#include<bits/stdc++.h>

using namespace std;

struct Item
{
	int value, weight;
};

bool comp(Item a,Item b)
{
	return ((double)a.value)/a.weight > ((double)b.value)/b.weight;
}

float Fraction(Item arr[],int W,int n) // W knapsack capacity
{
	sort(arr,arr+n,comp);

	int curr_weight = 0; //current weigth in knapsack
	 double final_value = 0.0; //final profit

	for(int i = 0 ; i < n ;i++)
	{
		if(curr_weight + arr[i].weight <= W) //can add full object
		{
			curr_weight += arr[i].weight;
			final_value += arr[i].value;
		}
		else{
			//Add fraction
			int remain = W - curr_weight;
			final_value += ((double)remain/arr[i].weight)*(arr[i].value);
			break;
		}
	}
	return final_value;


}



int main()
{
	int W = 50;   //    Weight of knapsack 
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}}; 
  
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    cout << "Maximum value we can obtain = "
         << Fraction(arr,W ,n); 
    return 0; 
}


