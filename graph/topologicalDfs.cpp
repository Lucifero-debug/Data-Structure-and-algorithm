#include <iostream>
using namespace std;

#include <bits/stdc++.h> 

void topo( unordered_map<int, list<int>>&adj, unordered_map<int,bool>&visited,int i,stack<int>&st){
visited[i]=true;
for(auto j:adj[i]){
  if (!visited[j]) {
 topo(adj,visited,j,st);
  }
st.push(i);
}
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    stack<int>st;
     unordered_map<int, list<int>>adj;
     vector<int>ans;
  for(int i=0;i<edges.size();i++){
    int u=edges[i][0];
    int v=edges[i][1];
    adj[u].push_back(v);
  }
 unordered_map<int,bool>visited;
 for(int i=0;i<v;i++){
    if (!visited[i]) {
    topo(adj,visited,i,st);
    }
 }
 while(!st.empty()){
     int b=st.top();
     st.pop();
ans.push_back(b);
 }
 return ans;
}

int main(){
return 0;
}