#include <iostream>
using namespace std;

class Queue{

int *arr;
int size;
int front;
int rear;

public:

Queue(int size){
this->size=size;
arr=new int[size];
front=0;
rear=0;
}

void push(int data){
if(rear==size){
    cout<<"queue is full"<<endl;
}else{
    arr[rear]=data;
    rear++;
}
}

int pop(){

if(front==rear){
    cout<<"queue is empty"<<endl;
    return -1;
}
else{
    int ans=arr[front];
    arr[front]=-1;
    front++;
    if(front==rear){
        front=0;
        rear=0;
    }
    return ans;
}

}

int top(){
if(rear==front){
    cout<<"queue is empty"<<endl;
    return -1;
}else{
    return arr[front];
}
}
bool isEmpty(){
    if(front==rear){
        cout<<"queue is empty"<<endl;
return true;
    }
    else{
        return false;
    }
}

};


int main(){
Queue qt(5);
qt.push(6);
cout<<qt.top()<<endl;
qt.push(8);
cout<<qt.top()<<endl;
qt.push(2);
cout<<qt.top()<<endl;
qt.pop();
cout<<qt.top()<<endl;
qt.pop();
cout<<qt.top()<<endl;
qt.pop();
cout<<qt.isEmpty()<<endl;
qt.pop();

    return 0;
}