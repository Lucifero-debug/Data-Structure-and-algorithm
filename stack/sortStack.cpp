#include <iostream>
using namespace std;

class Stack{
public:
int size;
int *arr;
int top;

Stack(int size){
    this->size=size;
    arr=new int[size];
    top=-1;
}

void push(int element){
if(size-top>1){
top++;
arr[top]=element;
}else{
    cout<<"stack overflow"<<endl;
}
}
void pop(){
    if(top>=0){
    top--;
    }else {
        cout<<"stack underflow"<<endl;
    }
}
int len(){
    if(top>-1) return top+1;
    else {
        cout<<"stack empty"<<endl;
        return -1;
    }
}
int peek(){
    if(top>-1){
        return arr[top];
    }else{
        cout<<"stack empty"<<endl;
        return -1;
    }
}
bool isEmpty(){
    if(top==-1){
        return true;
    }else return false;
}

};

void print(Stack s){
     int ans=0;
    while(!s.isEmpty()){
        ans=s.peek();
        cout<<ans<<" ";
        s.pop();
    }
    cout<<endl;
}

void sorted(Stack &s,int ans){
    if(s.isEmpty() || (!s.isEmpty()&& s.peek()<ans)){ s.push(ans); return;};
    int num=s.peek();
 s.pop();
 sorted(s,ans);
 s.push(num);
}

void solve(Stack &s){
    if(s.isEmpty()) return;
    int ans=s.peek();
    s.pop();
    solve(s);
    sorted(s,ans);
}

int main(){
Stack st(6);
st.push(3);
st.push(9);
st.push(23);
st.push(67);
st.push(91);
print(st);
solve(st);
cout<<"after"<<endl;
print(st);
    return 0;
}