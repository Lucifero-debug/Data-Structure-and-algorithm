#include <iostream>
using namespace std;
#include <vector>

void dfs(vector<bool>&visited,vector<int>&ans,int i,vector<int> adj[]){
    visited[i]=true;
    ans.push_back(i);
    
    for(auto j:adj[i]){
        if(!visited[j]){
            dfs(visited,ans,j,adj);
        }
    }
  }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans;
        vector<bool>visited(V);
        dfs(visited,ans,0,adj);
     return ans;
    }

int main(){
    return 0;
}


///time complexity:-o(ElogV)  E=edges  V=vertices
///space complexity:-O(N+E)