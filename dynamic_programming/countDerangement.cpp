#include <iostream>
using namespace std;
#define MOD 1000000007
#include <vector>


//top-down approach:-recursion + memoization
long long int solveMem(int n,vector<long long int>&dp){
    if(n==1) return 0;
    if(n==2) return 1;
    if(dp[n]!=-1) return dp[n];
    dp[n]=((n-1)%MOD*((solveMem(n-1, dp)%MOD)+(solveMem(n-2,dp)%MOD)))%MOD;
    return dp[n];
}

//bottom-up approach:-tabulation
long long int solveTwo(int n){
     vector<long long int>dp(n+1,-1);
  dp[1]=0;
  dp[2]=1;

for(long long int i=3;i<=n;i++){
    dp[i]=((i-1)%MOD*((dp[i-1]%MOD)+(dp[i-2]%MOD)))%MOD;
}
    return dp[n];
}

//space optimisation
long long int solveThree(int n){
  
  long long int prev1=0;
  long long int prev2=1;

for(long long int i=3;i<=n;i++){
    long long int curr=((i-1)%MOD*((prev1%MOD)+(prev2%MOD)))%MOD;
    prev1=prev2;
    prev2=curr;
}
    return prev2;
}


long long int countDerangements(int n) {
    // Write your code here.
    vector<long long int>dp(n+1,-1);
   return solveMem(n, dp);
   return solveTwo(n);
}