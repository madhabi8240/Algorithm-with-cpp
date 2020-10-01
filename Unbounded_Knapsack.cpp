#include<bits/stdc++.h>
#define M 1001 //Assuming input size
using namespace std;

int t[M][M];

int max(int a, int b)
{
	return (a>b?a:b);
}

int Unbounded_Knapsack(vector<int> &wt, vector<int> &val, int w, int n)
{
	//Inialization
	for(int i=0; i<M; i++)
	{
		t[0][i] = 0;
		t[i][0] = 0;
	}
	//Choice Diagram
	for(int i=1; i<n+1; i++)
	{
		for(int j=1; j<w+1; j++)
		{
			if(j>=wt[i-1])
				t[i][j] = max((val[i-1]+t[i][j-wt[i-1]]),t[i-1][j]);
			else
				t[i][j] = t[i-1][j];
		}
	}
	return t[n][w];
}

int main()
{
	int n,w;
	cin>>n>>w;
	vector<int> wt(n);
	vector<int> val(n);
	for(int i=0; i<n; i++)
		cin>>wt[i];
	for(int i=0; i<n; i++)
		cin>>val[i];
	memset(t,0,sizeof(t));
	cout<<Unbounded_Knapsack(wt,val,w,n)<<endl;
	return 0;
}
