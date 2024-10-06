#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void topo(int node,stack<int>&s,unordered_map<int,list<int>>&adj,vector<bool>&visited){
	visited[node]=true;
	for(auto i:adj[node]){
		if(!visited[i]){
			topo(i,s,adj,visited);
		}
	}
	s.push(node);
}

void dfs(int node,vector<bool>&visited,unordered_map<int,list<int>>&adj){
	visited[node]=true;
	for(auto i:adj[node]){
		if(!visited[i]){
    dfs(i,visited,adj);
		}
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Write your code here.
	//create adj list
	unordered_map<int,list<int>>adj;
	for(int i=0;i<edges.size();i++){
		int u=edges[i][0];
		int v=edges[i][1];

       adj[u].push_back(v);
	}
	//step 1:- topological
	vector<bool>visited(v,false);
	stack<int>s;
	for(int i=0;i<v;i++){
if(!visited[i]){
	topo(i,s,adj,visited);
}
	}
    //step 2:- transpose graph
	unordered_map<int,list<int>>newAdj;
	for(int i=0;i<edges.size();i++){
		int u=edges[i][0];
		int v=edges[i][1];

       newAdj[v].push_back(u);
	}
	int count=0;
		vector<bool>newVisited(v,false);
        //dfs to count scc
	while(!s.empty()){
		int front=s.top();
		s.pop();
     if(!newVisited[front]){
		 dfs(front,newVisited,newAdj);
		 count++;
	 }
	}
	return count;
}