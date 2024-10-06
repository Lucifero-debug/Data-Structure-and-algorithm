#include <iostream>
using namespace std;
#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
  //create adj list
   unordered_map<int, list<int>>adj;
   for(int i=0;i<edges.size();i++){
     int u=edges[i][0];
     int v=edges[i][1];
adj[u].push_back(v);
   }
   //create indegree array
   vector<int>indegree(v);
for(auto i:adj){
  for(auto j:i.second){
    indegree[j]++;
  }
}
queue<int>q;
//push aLL elements with zero indegree in zero
for(int i=0;i<v;i++){
  if(indegree[i]==0){
    q.push(i);
  }
}
vector<int>ans;
while(!q.empty()){
  int top=q.front();
  q.pop();
  ans.push_back(top);
  for(auto padosi:adj[top]){
    indegree[padosi]--;
    if(indegree[padosi]==0){
      q.push(padosi);
    }
  }
}
return ans;
}

int main(){
    return 0;
}