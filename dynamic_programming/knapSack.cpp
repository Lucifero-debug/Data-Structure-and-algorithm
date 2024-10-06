#include <bits/stdc++.h> 
#include <iostream>
using namespace std;


//top down:-recursion + memoization
int solve(vector<int>&weight, vector<int> &value,int index,int capacity,vector<vector<int>>&dp){
//base case
if(index==0){
	if(weight[0]<=capacity) return value[0];
	else return 0;
}
    if(dp[index][capacity]!=-1) return dp[index][capacity];
//include
int include=0;
if(weight[index] <= capacity)
include=value[index]+solve(weight,value,index-1,capacity-weight[index],dp);
//exclude 
int exclude=0+ solve(weight,value,index-1,capacity,dp);
dp[index][capacity]=max(include,exclude);
return dp[index][capacity];
}


//bottom up:-tabulation approach
int solveTwo(vector<int>&weight, vector<int> &value,int n,int capacity){
//base case
vector<vector<int>>dp(n,vector<int>(capacity+1,0));
for(int w=weight[0];w<=capacity;w++){
	if(weight[0]<=capacity) dp[0][w]=value[0];
	else dp[0][w]=0;
}
//include
for(int i=1;i<n;i++){
for(int w=0;w<=capacity;w++){
int include=0;
if(weight[i] <= w)
include=value[i]+dp[i-1][w-weight[i]];
//exclude 
int exclude=0+ dp[i-1][w];
dp[i][w]=max(include,exclude);
}
}
return dp[n-1][capacity];
}


//space optimisation
int solveThree(vector<int>&weight, vector<int> &value,int n,int capacity){
//base case
vector<int>prev(capacity+1,0);
vector<int>curr(capacity+1,0);
for(int w=weight[0];w<=capacity;w++){
	if(weight[0]<=capacity) prev[w]=value[0];
	else prev[w]=0;
}
//include
for(int i=1;i<n;i++){
for(int w=0;w<=capacity;w++){
int include=0;
if(weight[i] <= w)
include=value[i]+prev[w-weight[i]];
//exclude 
int exclude=0+ prev[w];
curr[w]=max(include,exclude);
}
prev=curr;
}

return prev[capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
   return solve(weight,value,n-1,maxWeight,dp);
   return solveTwo(weight,value,n,maxWeight);
   return solveThree(weight,value,n,maxWeight);
}