#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

long long int solve(vector<int>& nums, int n){
long long int prev1=nums[0];
long long int prev2=0;
for (int i = 1; i < n; i++) {
 long long int curr=max(prev2+nums[i],prev1);
  prev2=prev1;
  prev1=curr;
}
return prev1;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
     int n=valueInHouse.size();
       if (n == 0) return 0; 
       if (n == 1) return valueInHouse[0];
       vector<int>first,second;
    for(int i=0;i<n;i++){
        if(i!=n-1){
            first.push_back(valueInHouse[i]);
        }
        if(i!=0){
            second.push_back(valueInHouse[i]);
        }
    }

    return max(solve(first,n-1),solve(second,n-1));
}