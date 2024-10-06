#include <iostream>
using namespace std;
#include <vector>
#include <queue>

  vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans;
        vector<bool>visited(V,false);
        queue<int>q;
        q.push(0);
        visited[0]=true;
        while(!q.empty()){
            int first=q.front();
            q.pop();
            ans.push_back(first);
            for(auto i:adj[first]){
                if(!visited[i]){
                q.push(i);
                    visited[i]=true;
                }
            }
        }
        return ans;
    }

int main(){
    return 0;
}