#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

#include <bits/stdc++.h> 

//top down approach recursion+ memoization
int solve(vector<int> &nums,vector<int>&dp,int n){
//base case
if(n<0) return 0;
if(n==0) return nums[0];
      if(dp[n]!=-1) return dp[n];
int inc=solve(nums,dp,n-2)+nums[n];
int exc=solve(nums,dp,n-1)+0;
dp[n]=max(inc,exc);
return dp[n];
}

//tabulation approach
int solveTwo(vector<int> &nums,int n){
//base case
vector<int>dp(n+1,-1);
if(n<0) return 0;
if(n==0) return nums[0];
dp[0]=nums[0];
for (int i = 1; i <= n; i++) {
  int inc=nums[i]+dp[i-2];
  int exc=dp[i-1];
  dp[i]=max(inc,exc);
}
return dp[n];
}

//space optimisation
int solveThree(vector<int> &nums,int n){
//base case
int prev1=nums[0];
int prev2=0;
for (int i = 1; i <= n; i++) {
  int curr=max(prev2+nums[i],prev1);
  prev2=prev1;
  prev1=curr;
}
return prev1;
}


int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int>dp(n+1,-1);
    int ans=solve(nums,dp,n-1);
    return ans;
}

int main(){
    return 0;
}