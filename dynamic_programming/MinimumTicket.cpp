#include <vector>
#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//APPROACH top-down:-recursion+memoization
int solve(int n, vector<int>&days,vector<int>&cost,int index,vector<int>&dp){
//base case
if(index==n) return 0;

 if(dp[index]!=-1) return dp[index];
//for 1 days
int option1=cost[0]+solve(n,days,cost,index+1,dp);

//for 7 days
int i;
for(i=index;i<n && days[i]<days[index]+7;i++);
int option2=cost[1]+ solve(n,days,cost,i,dp);

//for 30 days
for(i=index;i<n && days[i]<days[index]+30;i++);
int option3=cost[2]+solve(n,days,cost,i,dp);

dp[index]=min(option1,min(option2,option3));
return dp[index];
}

//approach bottom up:-tabulation method
int solveTwo(int n, vector<int>&days,vector<int>&cost){
     vector<int>dp(n+1,0);
//base case
dp[n] = 0;
for(int j=n-1;j>=0;j--){
int option1=cost[0]+ dp[j+1];
int i;
for(i=j;i<n && days[i]<days[j]+7;i++);
int option2=cost[1]+ dp[i];
for(i=j;i<n && days[i]<days[j]+30;i++);
int option3=cost[2]+ dp[i];
dp[j]=min(option1,min(option2,option3));
}

return dp[0];
}
// approach 3:- space optimisation
int minimumCoin(int n, vector<int> days, vector<int> cost)
{
    int ans = 0;
    queue<pair<int,int>>month;
    queue<pair<int,int>>week;

    for(int day:days){
        //step 1:- remove expired days
        while(!month.empty() && month.front().first + 30<=day){
            month.pop();
        }
        while(!week.empty() && week.front().first + 7<=day){
            week.pop();
        }
        //step 2:- add cost for current day
        week.push(make_pair(day,ans+cost[1]));
        month.push(make_pair(day,ans+cost[2]));
//step 3:- update answer
ans=min(ans+cost[0],min(week.front().second,month.front().second));
    }
    return ans;
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    vector<int>dp(n+1,-1);
return solve(n,days,cost,0,dp);   
}