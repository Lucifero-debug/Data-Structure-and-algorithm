#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

//recursion TLE
 int solve(int a[],int n,int curr,int prev){
         if(curr>=n) return 0;
        //exclude
        int exclude=solve(a,n,curr+1,prev);
    //include
    int include=0;
    
        if(prev==-1||a[curr]>a[prev]){
    include=1+solve(a,n,curr+1,curr);
        }
        return max(include,exclude);
    }

//recursion + memoization
      int solveMem(int a[],int n,int curr,int prev,vector<vector<int>>&dp){
        if(curr==n) return 0;
           if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];
        //exclude
        int exclude=solveMem(a,n,curr+1,prev,dp);
    //include
    int include=0;
    
        if(prev==-1||a[curr]>a[prev]){
    include=1+solveMem(a,n,curr+1,curr,dp);
        }
       return  dp[curr][prev+1]=max(include,exclude);
    }

//approach 2:- tabulation method
  int solveTab(int a[],int n){
          vector<vector<int>>dp(n+1,vector<int>(n+1,0));
          
          for(int i=n-1;i>=0;i--){
              for(int j=i-1;j>=-1;j--){
                    int exclude=dp[i+1][j+1];
    //include
    int include=0;
    
        if(j==-1||a[i]>a[j]){
    include=1+dp[i+1][i+1];
        }
        dp[i][j+1]=max(include,exclude);
              }
          }
      
       return  dp[0][0];
    }

    //space optimisation
      int solveSO(int a[],int n){
         vector<int>curr(n+1,0);
          vector<int>next(n+1,0);
          
          for(int i=n-1;i>=0;i--){
              for(int j=i-1;j>=-1;j--){
                    int exclude=next[j+1];
    //include
    int include=0;
    
        if(j==-1||a[i]>a[j]){
    include=1+next[i+1];
        }
        curr[j+1]=max(include,exclude);
              }
        next=curr;
          }
      
       return next[0];
    }

    //most otimaL APPROACH:- DP WITH BINARY SEARCH
 int solveBS(int a[],int n){
         if(n==0) return 0;
         vector<int>ans;
         ans.push_back(a[0]);
         for(int i=0;i<n;i++){
             if(a[i]>ans.back()){
                 ans.push_back(a[i]);
             }else{
                 //find index of just bdaa elemnt
                 int index=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
                 ans[index]=a[i];
             }
         }
         return ans.size();
    }

    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int>ans;
     return solve(a,n,0,-1);
    
    }