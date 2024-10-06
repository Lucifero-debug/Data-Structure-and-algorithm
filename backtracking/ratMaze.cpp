#include <iostream>
using namespace std;
#include <bits/stdc++.h> 

bool isSafe(int x,int y,vector < vector < int >>visited,vector < vector < int >>arr,int n){
if(x<n && x>=0 && y<n&&y>=0&&!visited[x][y]&&arr[x][y]==1){
    return true;
}else{
    return false;
}
}

void solve(vector < vector < int >>& arr,vector < vector < int >> &visited,int n,int x,int y,string path,vector<string>&ans){
if(x==n-1&& y==n-1){
ans.push_back(path);
return;
}
visited[x][y]=1;
vector<pair<int,int>>move={{1,0},{0,-1},{0,1},{-1,0}};
vector<char>choice={'D','L','R','U'};
for(int i=0;i<4;i++){
    int newX=x+move[i].first;
    int newY=y+move[i].second;
    if(isSafe(newX,newY,visited,arr,n)){
        path+=choice[i];
        solve(arr,visited,n,newX,newY,path,ans);
        path.pop_back();
    }
}
        visited[x][y]=0;
}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    vector < vector < int >>visited(n, vector<int>(n, 0));
   vector<string> ans;
   int x=0;
   int y=0;
   string path="";
    solve(arr,visited,n,x,y,path,ans);
return ans;
}

int main(){

    return 0;
}