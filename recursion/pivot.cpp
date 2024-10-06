#include <iostream>
using namespace std;

int pivot(int *arr,int start,int end,int size){
    int mid=start+(end-start)/2;
    if(start>end) return -1;
    int next=(mid+1)%size;
    int prev=(mid-1+size)%size;
    if(arr[mid]<arr[next] &&arr[mid]<arr[prev]){
        return mid;
    }
    if(arr[mid]>arr[0]){
        return pivot(arr,mid+1,end,size);
    }
    if(arr[mid]<arr[size-1]){
        return pivot(arr,start,mid-1,size);
    }
}

int main(){
    int arr[6]={4,5,1,2,3};
int ans=pivot(arr,0,4,5);
cout<<"answer:"<<ans<<endl;
    return 0;
}