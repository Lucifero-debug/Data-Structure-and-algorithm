#include <iostream>
using namespace std;

void bubble(int *arr,int size){
    if(size==0 || size==1) return;
    for(int i=0;i<size-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    bubble(arr,size-1);
}

void print(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }
}

int main(){
    int arr[5]={7,2,9,4,1};
    bubble(arr,5);
    print(arr,5);
    return 0;
}