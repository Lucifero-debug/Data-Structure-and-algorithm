#include <iostream>
using namespace std;

class heap{
public:
int arr[100];
int size;

heap(){
    arr[0]=-1;
    size=0;
}

void insert(int val){
    size=size+1;
    int index=size;
    arr[index]=val;

    while(index>1){
        if(arr[index]>arr[index/2]){
            int c=arr[index];
            arr[index]=arr[index/2];
            arr[index/2]=c;
            index=index/2;
        }else{
            break;
        }
    }
}

void deleteFromHeap(){
    if(size==0){
        cout<<"Nothing to delete"<<endl;
        return;
    }
    //step 1:-swap last element with first
    arr[1]=arr[size];
    //step 2:-make last element inaccessible
    size--;
    //step 3:-propogate first element to its correct position
int i=1;
    while(i<size){
int left=2*i;
int right=2*i+1;
if(left<size && arr[left]>arr[i]){
    int c=arr[left];
    arr[left]=arr[i];
    arr[i]=c;
}
else if(right<size && arr[right]>arr[i]){
    int c=arr[right];
    arr[right]=arr[i];
    arr[i]=c;
}
else{
    break;
}
    }
}

void print(){
    for(int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

}
};

void heapify(int *arr,int n,int i){
int largest=i;
int left=2*i;
int right=2*i+1;
if(left<n && arr[largest]<arr[left]){
    largest=left;
}
if(right<n && arr[largest]<arr[right]){
    largest=right;
}
else{
    return;
}
if(largest!=i){
int c=arr[largest];
arr[largest]=arr[i];
arr[i]=c;
heapify(arr,n,largest);
}
}

int main(){

heap h;
h.insert(50);
h.insert(55);
h.insert(53);
h.insert(52);
h.insert(54);
h.print();
h.deleteFromHeap();
h.print();
int arr[6]={-1,54,53,55,52,50};
int n=5;
for(int i=n/2;i>0;i--){
heapify(arr,n,i);
}
cout<<"printing the array now"<<endl;
for(int i=1;i<=n;i++){
    cout<<arr[i]<<" ";
}cout<<endl;
    return 0;
}