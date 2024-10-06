#include <iostream>
using namespace std;

#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
//create adj list
     unordered_map<int,list<pair<int,int>>>adj;
    for(int i=0;i<g.size();i++){
    int u=g[i].first.first;
    int v=g[i].first.second;
    int w=g[i].second;
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
    }

    vector<int>key(n+1,INT_MAX);
    vector<int>parent(n+1,-1);
    vector<bool>mst(n+1,false);
    //start with zeroth node
    key[1]=0;
    parent[1]=-1;
    for(int i=1;i<n;i++){
        int min=INT_MAX;
        //finding index with min value in key array
        int u=-1;
        for(int v=1;v<=n;v++){
            if(!mst[v] && key[v]<min){
                u=v;
                min=key[v];
            }
        }
        //mark min node
        mst[u]=true;
        for(auto i:adj[u]){
            if(!mst[i.first]&&key[i.first]>i.second){
                key[i.first]=i.second;
            parent[i.first]=u;
            }
        }
    }
    vector<pair<pair<int, int>, int>>ans;
    for(int i=2;i<=n;i++){
        pair<int,int>p=make_pair(parent[i],i);
        int w=key[i];
        ans.push_back(make_pair(p,w));
    }
return ans;
}


int main(){
    return 0;
}