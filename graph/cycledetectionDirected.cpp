#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <list>

bool checkCycleDFS(int i,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsVisited,unordered_map<int, list<int>>&adj){
  visited[i]=true;
  dfsVisited[i]=true;

  for(auto j:adj[i]){
    if(!visited[j]){
      bool cycleFound=checkCycleDFS(j,visited,dfsVisited,adj);
      if(cycleFound) return true;
    }else if(dfsVisited[j]){
return true;
    }
  }
  dfsVisited[i]=false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  unordered_map<int, list<int>>adj;
  for(int i=0;i<edges.size();i++){
    int u=edges[i].first;
    int v=edges[i].second;

    adj[u].push_back(v);
  }

  //call dfs for all components
  unordered_map<int,bool>visited;
  unordered_map<int,bool>dfsVisited;
  for(int i=0;i<=n;i++){
    if(!visited[i]){
      bool cycleFound= checkCycleDFS(i,visited,dfsVisited,adj);
      if(cycleFound)
      return true;
    }
  }
  return false;
}

int main(){

    return 0;
}