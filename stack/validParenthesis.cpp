#include <iostream>
using namespace std;
#include <string>

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


bool valid(string str){
    int i=0;
    Stack st(str.length());
    while(str[i]!='\0'){

if(str[i]=='{' || str[i]=='[' || str[i]=='('){
st.push(str[i]);
}
else if(str[i]=='}' || str[i]==']' || str[i]==')'){
    char ch=st.peek();
    if(str[i]=='}' && ch=='{') st.pop();
   else if(str[i]==')' && ch=='(') st.pop();
   else if(str[i]==']' && ch=='[') st.pop();
}
i++;
    }
if(st.isEmpty()) return true;
else return false;
}

int main(){
    string str="({[]}";
   cout<< valid(str)<<endl;
    return 0;
}