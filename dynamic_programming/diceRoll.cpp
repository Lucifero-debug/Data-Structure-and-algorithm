#include <iostream>
using namespace std;
#include <vector>

//recursion+memo
  long long solve(int face, int dice, int target, vector<vector<int>>&dp){
      if(target<0) return 0;
      if(target==0 && dice!=0) return 0;
      if(target!=0 && dice==0) return 0;
      if(target==0 && dice==0) return 1;
         if(dp[dice][target]!=-1) return dp[dice][target];
      long long ans=0;
      for(int i=1;i<=face;i++){
          ans=ans+solve(face,dice-1,target-i,dp);
      }
      dp[dice][target]=ans;
      return ans;
  }

//tabulation approach
    long long solveTab(int face, int dice, int target){
         vector<vector<long long>>dp(dice+1,vector<long long>(target+1,0));
  dp[0][0]=1;
  for(int d=1;d<=dice;d++){
      for(int t=1;t<=target;t++){
        long long ans=0;
      for(int i=1;i<=face;i++){
          if(t-i>=0){
          ans=ans+dp[d-1][t-i];
          }
      }
      dp[d][t]=ans;   
      }
  }
    return dp[dice][target];
  }
  
//spcae optimisation

long long solveThree(int face, int dice, int target){

      
         vector<long long>curr(target+1,0);
         vector<long long>prev(target+1,0);
  prev[0]=1;
  for(int d=1;d<=dice;d++){
      for(int t=1;t<=target;t++){
        long long ans=0;
      for(int i=1;i<=face;i++){
          if(t-i>=0){
          ans=ans+prev[t-i];
          }
      }
      curr[t]=ans;   
      }
      prev=curr;
  }
    return prev[target];
  }

    long long noOfWays(int m, int n, int x) {
        // code here
        vector<vector<int>>dp(n+1,vector<int>(x+1,-1));
       return solve(m,n,x,dp);
    }
