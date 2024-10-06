#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmall(vector<int> arr,int n){
    stack<int> st;
    vector<int>ans(n);
    st.push(-1);
for(int i=n-1;i>=0;i--){
 int curr=arr[i];
while(st.top()!=-1&&curr<=arr[st.top()]){
    st.pop();
}
ans[i]=st.top();
st.push(i);
}
return ans;
}

vector<int> prevSmall(vector<int> arr,int n){
  stack<int> st;
  vector<int>ans(n);
    st.push(-1);
for(int i=0;i<n;i++){
 int curr=arr[i];
while(st.top()!=-1&&curr<=arr[st.top()]){
    st.pop();
}
ans[i]=st.top();
st.push(i);
}
return ans;
}

int histo(vector<int> arr,int n){
    int area=0,ans=0;
  for(int i=0;i<n;i++){
    vector<int>next=nextSmall(arr,n);
    vector<int>prev=prevSmall(arr,n);
    
    if(next[i]==-1) {
        next[i]=n;
    }
    int width=next[i]-prev[i]-1;
    area=width*arr[i];
    if(area>ans){
        ans=area;
    }
  }
    return ans;
}
vector<int> add(vector<int>one,vector<int>two,int size){
    vector<int>ans(size);
for(int i=0;i<size;i++){
    if(one[i]!=0){
ans[i]=one[i]+two[i];
    }else{
        ans[i]=0;
    }
}
return ans;
}

int max(vector<vector<int>> arr){
    int n=arr.size();
    int ans=histo(arr[0],n);
    for(int i=1;i<n;i++){
     vector<int> sum=add(arr[i],arr[i-1],n);
     int area=histo(sum,n);
     if(area>ans){
        ans=area;
     }
    }
    return ans;
}

int main(){
  vector<vector<int>> arr={{0,1,1,0},
         {1,1,1,1},
         {1,1,1,1},
         {1,1,0,0}};
         int ans=max(arr);
       cout<<ans<<endl;
    return 0;
}