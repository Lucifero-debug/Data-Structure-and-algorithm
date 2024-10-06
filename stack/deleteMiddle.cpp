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

void deleteMid(Stack& s,int len,int count){
if(count==len/2){
    s.pop();
    return;
}
int num=s.peek();
s.pop();
deleteMid(s,len,count+1);
s.push(num);
}

int main(){

Stack st(5);
st.push(3);
st.push(9);
st.push(23);
st.push(67);
st.push(91);
print(st);
int len=st.len();
int count=0;
deleteMid(st,len,count);
print(st);
    return 0;
}