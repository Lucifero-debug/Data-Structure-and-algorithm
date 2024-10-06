#include <iostream>
using namespace std;


#include <queue>
#include <unordered_map>
#include <vector>
#include <list>
#include<algorithm>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	  unordered_map<int, list<int>>adj;
   for(int i=0;i<edges.size();i++){
     int u=edges[i].first;
     int v=edges[i].second;
adj[u].push_back(v);
adj[v].push_back(u);
   }
   queue<int>q;
   vector<bool>visited(n,false);
   unordered_map<int,int>parent;
   q.push(s);
   visited[s]=true;
   parent[s]=-1;
   while(!q.empty()){
       int top=q.front();
       q.pop();
       for(auto padosi:adj[top]){
if(!visited[padosi]){
visited[padosi]=true;
parent[padosi]=top;
q.push(padosi);
}
       }
   }
   vector<int>ans;
int curr=t;
while (curr !=-1) {
       ans.push_back(curr);
       curr = parent[curr];
}
 reverse(ans.begin(), ans.end());
return ans;
}

