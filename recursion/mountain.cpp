#include <iostream>
using namespace std;

int peak(int *arr,int start,int end,int size){
int mid=start+(end-start)/2;
if(start>end) return -1;
if(arr[mid-1]<arr[mid] &&arr[mid]>arr[mid+1]){
    return mid;
}
else if(arr[mid-1]<arr[mid] && arr[mid]<arr[mid+1]){
    return peak(arr,mid+1,end,size);
}
else if(arr[mid-1]>arr[mid] && arr[mid]>arr[mid+1]){
    return peak(arr,start,mid-1,size);
}
}

int main(){
    int arr[6]={0,1,2,3,2,1};
int ans=peak(arr,0,4,6);
cout<<"answer:"<<ans<<endl;
    return 0;
}