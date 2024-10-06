#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {

  stack<int> st;
  int mini;

    public:       
    void push(int data) {
        
            if(st.empty()){
                st.push(data);
                mini=data;
            }else{
               if(data<mini){
               int value=2*data-mini;
               st.push(value);
               mini=data;
               }else{
            st.push(data);
               }
            }
        
    }

    void pop() {
     if(st.empty()){
         return ;
     }else{
         int curr=st.top();
         if(curr>mini){
             st.pop();
         }else{
             mini=2*mini-curr;
             st.pop();
         }
     }
    }

    int top() {
        if(st.empty()) return -1;
        int curr=st.top();
       if(curr>mini){
           return curr;
       }else{
          return mini;
       }
    }

    int getMin() {
      return mini;
    }  
};

int main(){
    int arr[5]={5,3,2,8,4};

    return 0;
}