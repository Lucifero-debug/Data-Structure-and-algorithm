#include <iostream>
using namespace std;

class TwoStack{
public:
int *arr;
int size;
int top1;
int top2;

TwoStack(int size){
    this->size=size;
    arr=new int[size];
    top1=-1;
    top2=size;
}
void push1(int element){
if(top2-top1>1){
top1++;
arr[top1]=element;
}else{
    cout<<"stack overflow"<<endl;
}
}
void push2(int element){
    if(top2-top1>1){
top2--;
arr[top2]=element;
}else{
    cout<<"stack overflow"<<endl;
}
}
void pop1(){
    if(top1>-1)
{
    top1--;
}else{
    cout<<"stack empty"<<endl;
}
}
void pop2(){
    if(top2<size){
        top2++;
    }else{
        cout<<"stack empty"<<endl;
    }
}
bool isEmpty(){}


};

int main(){

    return 0;
}