#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void dfs(int node,vector<int>&disc,vector<int>&low,vector<bool>&visited,vector<int>&parent,vector<int>&ap,int &timer,unordered_map<int,list<int>>&adj){
visited[node]=true;
disc[node]=low[node]=timer++;
int child=0;
for(auto i:adj[node]){
    if(i==parent[node]) continue;
    if(!visited[i]){
        parent[i]=node;
        dfs(i,disc,low,visited,parent,ap,timer,adj);
         low[node]=min(low[node],low[i]);
    
    //check for articulation point
    if(low[i]>=disc[node] && parent[node]!=-1){
ap[node]=1;
    }
    child++;
}else{
    //back edge visited h pr parent ni
     low[node]=min(low[node],disc[i]);
}
}
if(parent[node]==-1&&child>1){
ap[node]=1;
}
}

int main(){

int n=5;
int e=5;
vector<pair<int,int>>edges;
edges.push_back(make_pair(0,3));
edges.push_back(make_pair(3,4));
edges.push_back(make_pair(0,4));
edges.push_back(make_pair(0,1));
edges.push_back(make_pair(1,2));
//create adj list
unordered_map<int,list<int>>adj;

for(int i=0;i<edges.size();i++){
    int u=edges[i].first;
    int v=edges[i].second;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int timer=0;
vector<int>disc(n,-1);
vector<int>low(n,-1);
vector<bool>visited(n,false);
vector<int>parent(n,-1);
vector<int>ap(n,0);

for(int i=0;i<n;i++){
    if(!visited[i]){
        dfs(i,disc,low,visited,parent,ap,timer,adj);
    }
}

//print ap
cout<<"Articulation points are:"<<endl;
for(int i=0;i<n;i++){
    if(ap[i]!=0){
        cout<<i<<" ";
    }
}

    return 0;
}