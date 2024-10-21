#include <bits/stdc++.h> 
#include <iostream>
using namespace std;


//recursive TLE solution
 int solve(vector<int>& values,int i,int j){
        if(i+1==j) return 0;
        int ans=INT_MAX;
        for(int k=i+1;k<j;k++){
     ans=min(ans,values[i]*values[j]*values[k]+solve(values,i,k)+solve(values,k,j));
        }      
        return ans;
    }
//approach 1:- memoization
 int solveMem(vector<int>& values,int i,int j,vector<vector<int>> &dp){
        if(i+1==j) return 0;
         if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int k=i+1;k<j;k++){
       ans=min(ans,values[i]*values[j]*values[k]+solveMem(values,i,k,dp)+solveMem(values,k,j,dp));
        }   
        dp[i][j]=ans;
        return ans;
    }
    
    //tabulation
     int solveTab(vector<int>& values){
        int m=values.size();
         vector<vector<int>> dp(m, vector<int>(m, 0));
        
        int ans=INT_MAX;
        
     for(int i=m-1;i>=0;i--){
          int ans=INT_MAX;
         for(int j=i+2;j<m;j++){
               int ans=INT_MAX;
        for(int k=i+1;k<j;k++){    ans=min(ans,values[i]*values[j]*values[k]+dp[i][k]+dp[k][j]);
        };
        dp[i][j]=ans;
         }
     }
        return dp[0][m-1];
    }

    //space optimisation not possible

    int minScoreTriangulation(vector<int>& values) {
        int i=0;
        int j=values.size()-1;
         vector<vector<int>> dp(j+1, vector<int>(j+1, 0));
       return solve(values,i,j);
        
    }