#include<bits/stdc++.h>
#define MAX 20

using namespace std;


int lps[MAX];

void compute_lps(string pattern)
{
	int m = pattern.length();
	int len = 0; 

	lps[0] = 0; //first lps is always zero
	int i = 1;
	while(i < m)
	{
		if(pattern[i] == pattern[len]){
			len++;
			lps[i++] = len;  
		}

		else{
			if(len != 0)
				len = lps[len - 1];
			else
			{
				lps[i++] = 0;
			}

		}
	}

}

void KMP(string text,string pattern)
{
	int n = text.length();
	int m = pattern.length();
	compute_lps(pattern);

	int i = 0; // index for text
	int j = 0; // index for pattern

	while(i < n){

		if(text[i] == pattern[j]){
			i++;
			j++;
		}
		if(j == m){
			cout << "Pattern found at index : "<<i-j;
			j = lps[j-1];
		}
		else if(i < n && text[i] != pattern[j])
		{
			if(j!=0){
				j = lps[j-1];
			}
			else
				i++;
		}

	}

}


int main()
{
	string text,pattern;

	cout << "Enter the text : ";
	cin >> text;
	cout << "Enter the pattern : ";
	cin >> pattern;
	KMP(text,pattern);
	return 0;
}