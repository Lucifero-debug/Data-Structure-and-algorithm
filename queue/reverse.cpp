#include <iostream>
using namespace std;
#include <queue>
#include <stack>


  queue<int> rev(queue<int> q)
    {
        // add code here.
        stack<int> st;
        while(!q.empty()){
   int element=q.front();
   st.push(element);
   q.pop();
    }
    while(!st.empty()){
        int element=st.top();
        q.push(element);
        st.pop();
    }
    return q;
    }

int main(){
    
    return 0;
}