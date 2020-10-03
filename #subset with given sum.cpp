#include<bits/stdc++.h>
using namespace std;

// Count of subset with given sum (DP)

int subset(int *arr, int n, int sum) {  // Tabulation (Botton-Up)
	int dp[n+1][sum+1];
	
	// Initialisation
	for(int i = 0; i<sum+1; i++) dp[0][i] = 0;
	for(int i = 0; i<n+1; i++) dp[i][0] = 1;
	
	// States and Transitions
	for(int i = 1; i<n+1; i++) {
		for(int j = 0; j<sum+1; j++) {
			if(arr[i-1] <= j)
				dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
			
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	
	// Result
	return dp[n][sum];
}

int main() {
	int n, sum; cin>>n>>sum;
	int arr[n];
	for(int i = 0; i<n; i++) cin>>arr[i];
	cout<<subset(arr, n, sum)<<endl;
}

//__________________________________________________________________
/*
Sample Input:
6 10
2 3 5 6 8 10

Sample Output:
3

Explanation:
	Initialisation:
		if(sum == 0)
			We can always get a subset i.e { }. So dp[i][0] = 1, 0<=i<n+1;
		
		if(n == 0) i.e arr is empty.
			We can never get a subset with given sum. So dp[0][i] = 0, 0<i<sum+1;
		
		dp will look like this:
			  sum
		   	1 0 0 0 0
		   	1
			1
		   	1
		   	1


	States and Transition:
		states and transition are similar to "subset sum" problem and again this problem is a variation of famous "0/1 knapsack".
		we just have replaced all Boolean terms with Integer terms
		bool -> int
		|| -> +

	Result:
		Result will be stored at dp[n][sum]
		
		  		sum
		   	1 0 0 0 0
		   	1 x x x x
			1 x x x x
		   	1 x x x x
		   	1 x x x R
		
		R is result.
*/
