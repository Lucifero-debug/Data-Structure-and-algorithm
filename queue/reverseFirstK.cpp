#include <iostream>
using namespace std;
#include <stack>
#include <queue>

 queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        if (q.empty() || k > q.size() || k <= 0) {
            return q;
        }
        
        stack<int> st;
        for(int i=0;i<k;i++){
            int element=q.front();
            st.push(element);
            q.pop();
        }
    
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    int n=q.size()-k;
   for(int i=0;i<n;i++){
       q.push(q.front());
       q.pop();
   }
    return q;
};

int main(){
    return 0;
}