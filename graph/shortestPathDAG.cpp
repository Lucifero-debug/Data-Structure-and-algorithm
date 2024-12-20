#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class graph{
public:
unordered_map<int,list<pair<int,int>>>adj;

void addEdge(int u,int v, int weight){
    pair<int,int>p=make_pair(v,weight);
    adj[u].push_back(p);
}

void printAdj(){
    for(auto i:adj){
        cout<<i.first<<"->";
        for(auto j:i.second){
            cout<<"("<<j.first<<","<<j.second<<"), ";
        }cout<<endl;
    }
}

void dfs(int node,vector<bool>&visited,stack<int>&s){
visited[node]=true;
for(auto i:adj[node]){
    if(!visited[i.first]){
dfs(i.first,visited,s);
    }
}
s.push(node);
}
void ShortestPathDAG(int src,vector<int>&dist,stack<int>s){
        dist[src]=0;
        while(!s.empty()){
            int top=s.top();
            s.pop();
          if(dist[top]!=INT_MAX){
            for(auto i:adj[top]){
                if(dist[top]+i.second<dist[i.first]){
                    dist[i.first]=dist[top]+i.second;
                }
            }
          }
}
}
};


int main(){
    graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    g.printAdj();
int n=6; //total no of nodes
vector<bool>visited(n);
stack<int>s;
    //topological sort
    for(int i=0;i<n;i++){
        if(!visited[i]){
            g.dfs(i,visited,s);
        }
    }

    int src=1;
    vector<int>distance(n);
    for(int i=0;i<n;i++){
         distance[i]=INT_MAX;
       g.ShortestPathDAG(src,distance,s);

    }
       cout<<"answer is:"<<endl;
       for(int i=0;i<distance.size();i++){
        cout<<distance[i]<<" "<<endl;
       }cout<<endl;
    return 0;
}
