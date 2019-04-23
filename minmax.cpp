#include<bits/stdc++.h>

using namespace std;

struct Pair
{
	int min,max;
};

struct Pair get_min_max(int arr[],int low,int high)
{
	struct Pair minmax,mml,mmr;

	//Only one element
	if(low == high)
	{
		minmax.min = arr[low];
		minmax.max = arr[low];
		return minmax;
	}
	//Only 2 element

	if(high == low +  1)
	{
		if(arr[high] > arr[low])
		{
			minmax.min = arr[low];
			minmax.max = arr[high];
		}
		else{
			minmax.max = arr[low];
			minmax.min = arr[high];
		}
		return minmax;
	}

	int mid = (low + high) / 2;
	mml = get_min_max(arr,low,mid);
	mmr = get_min_max(arr,mid+1,high);

	//compare min and max of two parts

	if(mml.min < mmr.min)
	{
		minmax.min = mml.min;
	}
	else{
		minmax.min = mmr.min;
	}

	if(mml.max > mmr.max)
	{
		minmax.max = mml.max;
	}
	else{
		minmax.max = mmr.max;
	}

	return minmax;


}



int main()
{
	int n = 6;
	int arr[] = {1000,11,445,1,330,3000};
	struct Pair minmax = get_min_max(arr,0,5);
	cout << minmax.min <<minmax.max;

	return 0;
}