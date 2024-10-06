#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextSmall(int *arr,int n){
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

vector<int> prevSmall(int *arr,int n){
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

int histo(int *arr,int n){
    int area=0,ans=0;
  for(int i=0;i<n;i++){
    vector<int>next=nextSmall(arr,n);
    vector<int>prev=prevSmall(arr,n);
    cout<<"prev width of"<<arr[i]<<" "<<prev[i]<<endl;
    cout<<"next width of"<<arr[i]<<" "<<next[i]<<endl;
    if(next[i]==-1) {
        next[i]=n;
    }
    int width=next[i]-prev[i]-1;
    cout<<"total width"<<arr[i]<<" "<<width<<endl;
    area=width*arr[i];
    if(area>ans){
        ans=area;
    }
  }
    return ans;
}

int main (){
    int arr[6]={2,1,5,6,2,3};
   int ans= histo(arr,6);
   cout<<"answer"<<ans<<endl;
    return 0;
}