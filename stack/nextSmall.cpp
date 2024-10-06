#include <iostream>
using namespace std;
#include <vector>
#include <stack>

void small(int *arr,vector<int>&ans,int n){
    stack<int> st;
    st.push(-1);
for(int i=n-1;i>=0;i--){
 int curr=arr[i];
while(curr<=st.top()){
    st.pop();
}
ans[i]=st.top();
st.push(curr);
}
}

void print(vector <int>arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
int arr[5]={2,1,4,3,7};
vector <int> ans(5,-1);
small(arr,ans,5);
print(ans);
    return 0;
}