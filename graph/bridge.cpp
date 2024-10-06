#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void dfs(int node, vector<int>&parent, vector<int>&disc,vector<int>&low, vector<bool>&visited,int &timer,unordered_map<int,list<int>>&adj,vector<vector<int>>&result){
visited[node]=true;
disc[node]=low[node]=timer++;

for(auto nbr:adj[node]){
    if(nbr==parent[node]) continue;
    if(!visited[nbr]){
        parent[nbr]=node;
  dfs(nbr,parent,disc,low,visited,timer,adj,result);
  low[node]=min(low[node],low[nbr]);
  //check bridge
  if(low[nbr]>disc[node]){
      vector<int>ans;
      ans.push_back(node);
      ans.push_back(nbr);
      result.push_back(ans);
  }
    }else{
        //back edge visited h pr parent ni
     low[node]=min(low[node],disc[nbr]);
    }
}
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
    //create adj
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
       adj[u].push_back(v);
       adj[v].push_back(u);
    }

    vector<int>disc(v,-1);
    vector<int>low(v,-1);
    vector<int>parent(v,-1);
    vector<bool>visited(v,false);
    int timer=0;
    vector<vector<int>>result;
    for(int i=0;i<v;i++){
    if(!visited[i]){
        dfs(i,parent,disc,low,visited,timer,adj,result);
    }
    }
return result;
}