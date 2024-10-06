#include <iostream>
#include <vector>
using namespace std;

void maze(int arr[4][4],vector<string>& ans,int visited[4][4],int x,int y,int n,string path){
if(x==n-1 && y==n-1){
    ans.push_back(path);
    return;
}
visited[x][y]=1;
//down x=x+1 y=y
if(x+1<n && !visited[x+1][y] && arr[x+1][y]){
     maze(arr,ans,visited,x+1,y,n,path+('D'));
}
//right x=x y=y+1
if(y+1<n && !visited[x][y+1] &&arr[x][y+1]){
     maze(arr,ans,visited,x,y+1,n,path+('R'));
}
//left x=x y=y-1
if(y-1>=0 && !visited[x][y-1] &&arr[x][y-1]){
     maze(arr,ans,visited,x,y-1,n,path+'L');
}
//top x=x-1 y=y
if(x-1>=0 && !visited[x-1][y] &&arr[x-1][y]){
     maze(arr,ans,visited,x-1,y,n,path+'T');
}
visited[x][y]=0;
}

int main(){
    int arr[4][4]={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<string>ans;
    int visited[4][4]={0};
    int srcx=0;
    int srcy=0;
  maze(arr,ans,visited,srcx,srcy,4,"");
  for (const string& path : ans) {
        cout << path << endl;
    }
    return 0;
}