#include <bits/stdc++.h> 
#include <iostream>
using namespace std;
#define MOD 1000000007


//top down approach:-recursion and memoization
int solve(int nStairs,int i,vector<int>&dp){
    //base case
    if(i==nStairs) return 1;
    if(i>nStairs) return 0;

      if(dp[i]!=-1) return dp[i];
     dp[i]=(solve(nStairs,i+1,dp) + solve(nStairs,i+2,dp))%MOD;
        return dp[i];
}

//bottom up:-tabulation approach
int solveTwo(int nStairs){
     vector<int>dp(nStairs+1,-1);
    //base case
    dp[1]=1;
    dp[0]=1;

    for(int i=2;i<=nStairs;i++){
        dp[i]=(dp[i-1] + dp[i-2])%MOD;
    }
    return dp[nStairs];
}

//space optimisation

int solveThree(int nStairs,vector<int>&dp){
    //base case
    if (nStairs == 0) return 1;
    if (nStairs == 1) return 1;
  int prev1=1;
  int prev2=1;
   for(int i=2;i<=nStairs;i++){
       int curr=(prev1+prev2)%MOD;
         prev2=prev1;
                prev1=curr;
   }
   return (prev1);
}


int countDistinctWays(int nStairs) {
    //  Write your code here.
    if(nStairs==0) return 1;
    vector<int>dp(nStairs+1,-1);
    int ans=solve(nStairs,0,dp);
    return ans;
}