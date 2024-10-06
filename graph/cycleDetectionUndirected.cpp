#include <queue>
#include <unordered_map>
#include <vector>
#include <list>
#include <string>


bool isCyclic(int i, unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adj){
unordered_map<int,int>parent;
queue<int>q;
q.push(i);
visited[i]=true;
parent[i]=-1;
while(!q.empty()){
    int first=q.front();
    q.pop();
    for(auto i:adj[first]){
        if(visited[i] && i!=parent[first]){
            return true;
        }
     if(!visited[i]){
visited[i]=true;
parent[i]=first;
q.push(i);
        }
    }
}
return false;
}

bool isCyclicDfs(int i,int parent,unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adj){
    visited[i]=true;

    for(auto j:adj[i]){
        if(!visited[j]){
           bool ans = isCyclicDfs(j,i,visited,adj);
           if(ans){
               return true;
           }
        }
        else if(j!=parent){
return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
unordered_map<int,list<int>>adj;
 for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

     adj[u].push_back(v);
     adj[v].push_back(u);
    }
    unordered_map<int,bool>visited;
   for(int i=0;i<n;i++){
       if(!visited[i]){
           bool ans=isCyclicDfs(i,-1,visited,adj);
           if(ans==1){
               return "Yes";
           }
       }
   }
  return "No";
}
