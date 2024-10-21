#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

//top-down approach:-recursion+memoization
 int solve(int n,vector<int>&dp){
      //base case 
      if(n<=0) return 0;
       if(dp[n]!=-1) return dp[n];
      int min_ways=INT_MAX;
      for(int i=1;i*i<=n;i++){
          int square=i*i;
          min_ways=min(min_ways,1+(solve(n-square,dp)));
      }
     dp[n]=min_ways;
     return dp[n];
  }

  //bottom up approach:-tabulation
   int solveTwo(int n){
      //base case
        vector<int>dp(n+1,INT_MAX);
      dp[0]=0;
      for(int j=1;j<=n;j++){
      for(int i=1;i*i<=j;i++){
          int square=i*i;
          dp[j]=min(dp[j],1+dp[j-square]);
      }
      }
     return dp[n];
  }

  //space optimisation not possible
  
    int MinSquares(int n) {
        // Code here
        vector<int>dp(n+1,-1);
        return solve(n,dp);
        return solveTwo(n);
    }