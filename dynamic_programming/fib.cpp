#include<bits/stdc++.h>
using namespace std;

//top down approach:-recursion and memoization
int fib(int n,vector<int>&dp){
        //base case
        if(n<=1) return n;
        //step 3
        if(dp[n]!=-1) return dp[n];

        //step 2
        dp[n]=fib(n-1,dp) + fib(n-2,dp);
        return dp[n];
}

//bootom up:-tabulation approach
int fibTwo(int n,vector<int>&dp){
dp[0]=0;
dp[1]=1;
for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
}
return dp[n];
}

//space optimisation approach
int fibThree(int n){
         int prev1=1;
        int prev2=0;
        if(n==0) return prev2;
        for(int i=2;i<=n;i++){
                int curr=prev1+prev2;
                prev2=prev1;
                prev1=curr;
        }
        return prev1;
}

int main()
{
        /*
        *  Write your code here. 
         *  Read input as specified in the question.
         *  Print output as specified in the question.
        */
        int n;
        cin>>n;
        vector<int>dp(n+1);
        for(int i=0;i<=n;i++)
        dp[i]=-1;
        cout<<fib(n,dp)<<endl;
        return 0;
}