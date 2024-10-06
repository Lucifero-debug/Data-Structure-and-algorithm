#include <iostream>
using namespace std;

#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    unordered_map<int,list<pair<int,int>>>adj;
    for(int i=0;i<edges;i++){
    int u=vec[i][0];
    int v=vec[i][1];
    int w=vec[i][2];
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
    }

    set<pair<int,int>>s;
    vector<int>dist(vertices,INT_MAX);
    dist[source]=0;
    pair<int,int>g=make_pair(0,source);
    s.insert(g);
    while(!s.empty()){
       auto top = *(s.begin());
     s.erase(s.begin());
     int node=top.second;
     int nodeWeight=top.first;
      for(auto i:adj[node]){
        int neighbour=i.first;
        int neighbourWeight=i.second;
          if(dist[neighbour]>nodeWeight+neighbourWeight){
              auto it = s.find(make_pair(dist[neighbour], neighbour));
              if (it != s.end()) {
                s.erase(it);
              }
              dist[neighbour] = nodeWeight + neighbourWeight;
              pair<int, int> p = make_pair(dist[neighbour], neighbour);
              s.insert(p);
          }
      }
    }
return dist;
}

int main(){
    return 0;
}