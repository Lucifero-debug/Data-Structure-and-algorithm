#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

//top down approach:-recusrison+memoization
int solve(vector<int> &num, int tar,vector<int>&dp){
    if(tar==0) return 1;
    if(tar<0) return 0;
        if (dp[tar] != -1) return dp[tar];
        int ways=0;
for(int i=0;i<num.size();i++){
    ways+=solve(num,tar-num[i],dp);
}
dp[tar]=ways;
return dp[tar];
}

//bottom up approach:-tabulation
int solveTwo(vector<int> &num, int tar){
      vector<int>dp(tar+1,-1);
     dp[0]=1;
    if(tar<0) return 0;
        for(int j=1;j<=tar;j++){
        int ways=0;
for(int i=0;i<num.size();i++){
  if (j - num[i] >= 0) { // Ensure we're not accessing out of bounds
    ways += dp[j - num[i]];
  }
            }
dp[j]=ways;
        }
return dp[tar];
}

//space optimisation not posssible


int findWays(vector<int> &num, int tar)
{
    // Write your code here.
   vector<int>dp(tar+1,-1);
   return solve(num,tar,dp);
   return solveTwo(num,tar);
}