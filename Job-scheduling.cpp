#include<bits/stdc++.h>

using namespace std;

struct Job{
	char id;
	int dead;
	int profit;
};

bool compare(Job a,Job b)
{
	return a.profit > b.profit;
}


void job_scheduling(Job arr[],int n)
{
	sort(arr,arr+n,compare); //sort in decresaing order
	int result[n]; //Keep track of sequence
	bool slot[n]; // to keep track of slot

	for(int i = 0 ; i < n ;i++) //Initialize all slots to be free
	{
		slot[i] = false;

	}

	for(int i = 0; i < n ;i++)
	{
		//Start from last possible slot
		for(int j = min(n,arr[i].dead) - 1;j>=0 ;j--)
		{
			if(slot[j] == false) //slot found
			{
				result[j] = i;
				slot[j] = true;
				break;

			}
		}
	}

	for(int i = 0 ; i < n ; i++)
		if(slot[i])
			cout << arr[result[i]].id << " ";

}

int main()
{


	Job arr[] = {
	{'a', 2, 100},
	{'b', 1, 19},
	{'c', 2, 27},
	{'d', 1, 25},
	{'e', 3, 15}
	};

	int n = 5;

	job_scheduling(arr,n);
	return 0;
}