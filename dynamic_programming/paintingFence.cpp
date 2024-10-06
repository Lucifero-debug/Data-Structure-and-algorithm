#include <bits/stdc++.h> 
#include <iostream>
using namespace std;
#define MOD 1000000007

int add(int a,int b){
    return (a%MOD + b%MOD)%MOD;
}

int mul(int a,int b){
    return ( (a%MOD)* 1LL * (b%MOD) )%MOD;
}

//top-down approach:-recursion + memoization
int solve(int n,int k,vector<int>&dp){
    if(n==1) return k;
    if(n==2) return add(k,mul(k,k-1));
    if(dp[n]!=-1) return dp[n];
   int first=mul(solve(n-1,k,dp),k-1);
   int second=mul(solve(n-2,k,dp),k-1);
   dp[n]=add(first,second);
    return dp[n];
}

//bottom-up approach:-tabulation
int solveTwo(int n,int k){
     vector<int>dp(n+1,-1);
    dp[1]= k;
    dp[2]= add(k,mul(k,k-1));

    for(int i=3;i<=n;i++){
   int first=mul(dp[i-1],k-1);
   int second=mul(dp[i-2],k-1);
   dp[i]=add(first,second);
    }
    return dp[n];
}

// space optimisation
int solveThree(int n,int k){
    int prev1= k;
    int prev2= add(k,mul(k,k-1));

    for(int i=3;i<=n;i++){
   int first=mul(prev2,k-1);
   int second=mul(prev1,k-1);
   int curr=add(first,second);
   prev1=prev2;
   prev2=curr;
    }
    return prev2;
}

int numberOfWays(int n, int k) {
    // Write your code here.
    vector<int>dp(n+1,-1);
   return solve(n,k,dp);
   return solveTwo(n,k);
   return solveThree(n,k);
}
