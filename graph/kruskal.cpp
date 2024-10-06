#include <iostream>
using namespace std;
#include <vector>

#include <algorithm>

void makeSet(vector<int>&parent,vector<int>&rank,int n){
  for(int i=0;i<n;i++){
    parent[i]=i;
    rank[i]=0;
  }
}

int findParent(vector<int>&parent,int node){
  if(parent[node]==node){
    return node;
  }
  return parent[node]=findParent(parent, parent[node]);
}

void unionSet(int u,int v,vector<int>&parent,vector<int>&rank){
  u=findParent(parent,u);
  v=findParent(parent,v);
  int a=rank[u];
  int b=rank[v];
  if(u!=v){
  if(a<b){
    parent[u]=v;
  }
  else if(a>b){
    parent[v]=u;
  }
  else{
    parent[v]=u;
    rank[u]++;
  }

  }
}
bool cmp(vector<int>&a,vector<int>&b){
  return a[2] < b[2];   //weight is in the last column
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  /*
    Don't write main().
    Don't read input, it is passed as function argument.    
    No need to print anything.
    Taking input and printing output is handled automatically.
  */
  vector<int>parent(n);
  vector<int>rank(n);
  makeSet(parent, rank,  n);
  int ans=0;
//step 1 sorting edges on the basis of weight
sort(edges.begin(),edges.end(),cmp);
//step 2  traversing edges
for(int i=0;i<edges.size();i++){
 int u=findParent(parent, edges[i][0]);
 int v=findParent(parent, edges[i][1]);
 if(u!=v){
   ans+=edges[i][2];
unionSet(u, v, parent,rank);
 }
}
//step 3:- calculate total weight
return ans;
}

int main(){
    return 0;
}