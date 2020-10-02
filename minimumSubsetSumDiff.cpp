
  // Minimum subset sum diff
#include<bits/stdc++.h>
#include<stdlib.h>
#include<algorithm>
#include <iostream>
using namespace std;

int findMinDiff(int arr[],int n,int sum)
{
    bool t[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
             if(i==0)
               t[i][j]=true;
            if(j==0)
               t[i][j]=false;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[j-1]<=i)       
                  t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
              else
                  t[i][j]=t[i-1][j]; 
        }
    }
    int diff=INT_MAX;
     for(int j=sum/2;j>=0;j--)
     {
        if(t[n][j]==true)
        {
            diff=sum-2*j;  //Range-2*S1
            break;
        }
     }
  return diff;
}
int main() {
	    int n;
	    cout<<"array size : ";
	    cin>>n;
	    int arr[n];
	    cout<<"array element :\n";
        int sum=0;
 	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        sum+=arr[i];
 	    }
	 cout<<findMinDiff(arr,n,sum);
	return 0;
}
