#include <bits/stdc++.h> 
#include <iostream>
using namespace std;


//top-down approach:-recursion and memoization
int solve(vector<int> &num, int x,vector<int>&dp){
//base case
if(x==0) return 0;
if(x<0) return INT_MAX;
 if(dp[x]!=-1) return dp[x];
int mini=INT_MAX;
for(int i=0;i<num.size();i++){
    int result= solve(num,x-num[i],dp);
    if(result!=INT_MAX){
    mini=min(mini,1+result);
    }
}
dp[x]=mini;
return dp[x];
}

// bottom-up approach:-tabulation

int solveTwo(vector<int> &num, int x){
    vector<int>dp(x+1,INT_MAX);
//base case
dp[0]=0;
for(int i=1;i<=x;i++){
    for(int j=0;j<num.size();j++){
        if(i-num[j]>=0 && dp[i-num[j]]!=INT_MAX){
            dp[i]=min(dp[i],1+dp[i-num[j]]);
        }
    }
}
if(dp[x]==INT_MAX) return -1;
return dp[x];
}

//space optimisation not possible

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n=num.size();
    vector<int>dp(x+1,-1);
    int ans=solve(num,x,dp);
    if(ans==INT_MAX) return -1;
    return ans;
}