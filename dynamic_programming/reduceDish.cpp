#include <bits/stdc++.h> 
#include <iostream>
using namespace std;


//TLE recursion onlly
  int solve(vector<int>& satisfaction,int i,int time){
        if(i>=satisfaction.size()) return 0;
        int include=satisfaction[i]*(time+1)+solve(satisfaction,i+1,time+1);
        int exclude=solve(satisfaction,i+1,time);
        int ans=max(include,exclude);
        return ans;
    }

  //approach 1:-recursion+memoization
 int solveMem(vector<int>& satisfaction,int i,int time,vector<vector<int>>&dp){
        if(i>=satisfaction.size()) return 0;
         if(dp[i][time]!=-1) return dp[i][time];
        int include=satisfaction[i]*(time+1)+solveMem(satisfaction,i+1,time+1,dp);
        int exclude=solveMem(satisfaction,i+1,time,dp);
        int ans=max(include,exclude);
        dp[i][time]=ans;
        return ans;
    }
//approach 2:-tabulation
   int solveTab(vector<int>& satisfaction){
        int n=satisfaction.size(); 
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=n-1;i>=0;i--){
            for(int time=i;time>=0;time--){
                 int include=satisfaction[i]*(time+1)+dp[i+1][time+1];
        int exclude=dp[i+1][time];
        int ans=max(include,exclude);
                dp[i][time]=ans;
            } 
        }
        return dp[0][0];
    }
//space optimisation
int solveSO(vector<int>& satisfaction){
          int n=satisfaction.size(); 
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);
         for(int i=n-1;i>=0;i--){
            for(int time=i;time>=0;time--){
                 int include=satisfaction[i]*(time+1)+next[time+1];
        int exclude=next[time];
        int ans=max(include,exclude);
                curr[time]=ans;
            } 
             next=curr;
        }
        return next[0];
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
         vector<vector<int>> dp(n, vector<int>(n, 0));
     return  solve(satisfaction,0,0);
    }