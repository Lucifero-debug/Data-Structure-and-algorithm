#include <iostream>
using namespace std;

void print(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }
}

void selection(int *arr,int size){
if(size==0 || size==1) return;
int min=0;
for(int i=0;i<size;i++){
    if(arr[min]>arr[i]){
     swap(arr[min],arr[i]);
    }
}
print(arr,size);
selection(arr+1,size-1);
}


int main(){
    int arr[5]={50,22,86,42,11};
    selection(arr,5);
    print(arr,5);
    return 0;
}