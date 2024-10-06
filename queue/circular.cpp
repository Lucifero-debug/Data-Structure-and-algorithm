#include <iostream>
using namespace std;

class Queue{
int *arr;
int rear;
int front;
int size;

public:
Queue(int size){
    this->size=size;
    arr=new int[size];
    rear=-1;
    front=-1;
}

void push(int data){
if((front==0 && rear==size-1)|| (rear == (front - 1) % (size - 1))){
    cout<<"queue is full"<<endl;
}
//cyclic case
else if(rear==size-1 && front!=0){
    rear=0;
}
//first element
else if(rear==-1){
    rear=0;
    front=0;
}
else{
    rear++;
}
arr[rear]=data;
}

int pop(){
if(front==-1){
    cout<<"queue is empty"<<endl;
    return -1;
}
int ans=arr[front];
arr[front]=-1;
//cyclic case
if(front==size-1 && rear!=0){
    front=0;
}
//queue becomes empty
else if(front==rear){
rear=-1;
front=-1;
}
else{
    front++;
}
return ans;
}
};


int main(){

    return 0;
}