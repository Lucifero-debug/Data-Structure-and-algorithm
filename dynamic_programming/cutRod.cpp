#include <iostream>
using namespace std;
#include <bits/stdc++.h>


//top down approach:-recursion + memoization
int solve(int n, int x, int y, int z,vector<int>&dp){
	//base case
	if(n==0) return 0;
	if(n<0) return INT_MIN;
	 if(dp[n]!=-1) return dp[n];
     int a=solve(n-x,x,y,z,dp)+1;
	 int b=solve(n-y,x,y,z,dp)+1;
	 int c=solve(n-z,x,y,z,dp)+1;
	 dp[n]=max(a,max(b,c));
	 return dp[n];
}

//tabulation
int solveTwo(int n, int x, int y, int z){
	//base case
	vector<int>dp(n+1,INT_MIN);
dp[0]=0;
        for (int i = 1; i <= n; i++) {
          if (i >= x)
            dp[i] = max(dp[i], dp[i - x] + 1);
          if (i >= y)
            dp[i] = max(dp[i], dp[i - y] + 1);
          if (i >= z)
            dp[i] = max(dp[i], dp[i - z] + 1);
        }
         return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	vector<int>dp(n+1,-1);
	int ans=solve(n,x,y,z,dp);
	if(ans<0) return 0;
	else return ans;
}