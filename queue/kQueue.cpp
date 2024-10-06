#include <iostream>
using namespace std;

class kQueue{
int *arr;
int *next;
int *rear;
int *front;
int free;

public:
kQueue(int N,int K){
arr=new int[N];
next=new int[N];
for(int i=0;i<N;i++){
    next[i]=i+1;
    if(i==N-1) next[i]=-1;
}
rear=new int[K];
front=new int[K];
for(int i=0;i<K;i++){
    rear[i]=-1;
    front[i]=-1;
}
free=0;
}

void push(int data,int m){
    //check fro full
    if(free==-1){
        cout<<"queue overflow"<<endl;
        return;
    }
    //find index
    int index=free;
    //update free
    free=next[index];
    //check for first
    if(front[m-1]==-1){
        front[m-1]=index;
    }else{
        next[rear[m-1]]=index;
    }
    //update next to full
    next[index]=-1;
    //update rear
    rear[m-1]=index;
    //insert data
    arr[index]=data;
}
int pop(int m){
    //check for empty
    if(front[m-1]==-1){
        cout<<"queue underflow"<<endl;
        return -1;
    }
    //find index to pop 
    int index=front[m-1];
    int ans=arr[index];
    //update front to its next
    front[m-1]=next[index];
    //update next and free
    next[index]=free;
    free=index;
    return ans;
}
};


int main(){

    return 0;
}