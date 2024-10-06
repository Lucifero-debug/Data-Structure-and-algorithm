#include <iostream>
using namespace std;
#include <bits/stdc++.h>


vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    // Write your code here.
    int maxi = 1e8;
    vector<int>dist(n+1,maxi);
//n-1 times
dist[src]=0;
    for(int i=1;i<n;i++){
      for(int j=0;j<m;j++){
          int u=edges[j][0];
          int v=edges[j][1];
          int w=edges[j][2];

          if(dist[u]!=maxi && dist[u]+w<dist[v]){
              dist[v]=dist[u]+w;
          }
      }
    }
    // check for negative cycle
    // bool flag=0;
    //  for(int j=0;j<m;j++){
    //       int u=edges[j][0];
    //       int v=edges[j][1];
    //       int w=edges[j][2];

    //       if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
    //           flag=1;
    //       }
    //   }
    //   if(flag==0){
    //       return dist;
    //   }else{
    //       return {};
    //   }
    return dist;
}