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

class Queue{
Stack *st;
int size;
int top;
int rear;

public:
Queue(int size){
    this->size=size;
 st=new Stack[size];
    top=0;
    rear=0;
}
void push(int data){
    st.push(data);
}
int pop(){
    for(int i=0;i<size-1;i++){
        st.pop();
    }
    return st.peek();
}
};

int main(){

    return 0;
}