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

int main(){

Stack st(5);
st.push(6);
cout<<st.peek()<<endl;
st.push(9);
cout<<st.peek()<<endl;
st.push(76);
cout<<st.peek()<<endl;
st.pop();
cout<<"after pop"<<endl;
cout<<st.peek()<<endl;
st.pop();
cout<<st.peek()<<endl;
cout<<st.len()<<endl;
    return 0;
}