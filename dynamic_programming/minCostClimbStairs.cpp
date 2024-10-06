#include <bits/stdc++.h> 
#include <iostream>
using namespace std;
class Solution {
public:
//top down approach :-recursion and memoization
    int solve(vector<int>& cost,int i,int n,vector<int>&dp){
      if(i>=n) return 0;    
         if(dp[i]!=-1) return dp[i];
        dp[i]=cost[i] + min(solve(cost,i+1,n,dp),solve(cost,i+2,n,dp));
        return dp[i];
    }
    //bottom up approach:-tabulation
     int solveTwo(vector<int>& cost,int n){
         vector<int>dp(n+1,-1);
    dp[0]=cost[0];
    dp[1]=cost[1];
     for(int i=2;i<n;i++){
         dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
     }
        return min(dp[n-1],dp[n-2]);
    }
    //space optimisation
     int solveThree(vector<int>& cost,int n){
      int prev1=cost[1];
       int prev2=cost[0];
for(int i=2;i<n;i++){
    int curr=cost[i]+min(prev1,prev2);
      prev2=prev1;
                prev1=curr;
}
       return min(prev1,prev2);
       }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
          vector<int>dp(n+1,-1);
        int ans=min(solve(cost,0,n,dp),solve(cost,1,n,dp));
         int ansTwo=(solveTwo(cost,n));
         int ansThree=(solveThree(cost,n));
        return ans;
    }
};