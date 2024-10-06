#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.

   unordered_map<int, list<int>>adj;
   for(int i=0;i<edges.size();i++){
     int u=edges[i].first;
     int v=edges[i].second;
adj[u].push_back(v);
   }
   //create indegree array
   vector<int>indegree(n+1, 0);
for(auto i:adj){
  for(auto j:i.second){
    indegree[j]++;
  }
}
queue<int>q;
//push aLL elements with zero indegree in zero
for(int i=1;i<n;i++){
  if(indegree[i]==0){
    q.push(i);
  }
}
int cnt=0;
while(!q.empty()){
  int top=q.front();
  q.pop();
  cnt++;
  for(auto padosi:adj[top]){
    indegree[padosi]--;
    if(indegree[padosi]==0){
      q.push(padosi);
    }
  }
}

if(cnt==n){
  return false;
}else{
  return true;
}

}                             

int main(){
    return 0;
}