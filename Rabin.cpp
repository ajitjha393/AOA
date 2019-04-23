#include<bits/stdc++.h>

using namespace std;

#define d 256

void rabin(string pattern,string text,int q) // A prime number
{
	int m = pattern.length();
	int n = text.length();
	int i,j;
	int p = 0; // hash value for text
	int t = 0; // hash value for pattern 
	int h = 1;

	for(int i = 0 ; i < m -1 ; i++)
	{
		h = (h*d)%q;
	}

	//Caculate hash value for pattern and window of text

	for(int i = 0 ; i < m ; i++)
	{
		p = (d*p + pattern[i]) % q;
		t = (d*t + text[i])%q;
	} 

	//SLIDE PATTERN ONE BY ONE

	for(i = 0 ; i <= n- m;i++)
	{
		//If hash values match then check for pattern
		if(p == t)
		{
			for( j = 0 ; j < m ; j++)
			{
				if(text[i+j] != pattern[j])
					break;
			}

			if(j == m)
				cout << "Pattern found at index : "<<i<<endl;
		}


		if(i < n - m) // Remove leading digit and add last digit
		{
			 t = (d*(t - text[i]*h) + text[i+m])%q; 

			 //we might get negative value 
			 if(t < 0)
			 	t = t +q;
		}
	}

}




int main()
{

	string pattern,text;

	
	cout << "Text : ";
	cin >> text;

	cout << "Pattern : ";
	cin >> pattern;

	int q = 101; // A prime number
	rabin(pattern,text,q);
	return 0;
}