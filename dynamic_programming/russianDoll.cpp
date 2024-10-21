   #include <bits/stdc++.h> 
#include <iostream>
using namespace std;
   //sort the 2d ont he bease od width if width equal then descending height
   void sorts(vector<vector<int>>& envelopes,int n){
       sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1]; // Descending for heights when widths are equal
        }
        return a[0] < b[0]; // Ascending for widths
    });
    }
//then implement dp with binary search on height column that is second column of envelope
    int solve(vector<vector<int>>&a,int n){
       if(n==0) return 0;
         vector<int>ans;
         for(int i=0;i<n;i++){
             if(ans.empty()||a[i][1]>ans.back()){
                 ans.push_back(a[i][1]);
             }else{
                 //find index of just bdaa elemnt
                 int index=lower_bound(ans.begin(),ans.end(),a[i][1])-ans.begin();
                 ans[index]=a[i][1];
             }
         }
         return ans.size();
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sorts(envelopes,n);
        return solve(envelopes,n);
    }