#include <iostream>
using namespace std;

int first(int *arr,int start,int end,int size,int target){
int mid=start+(end-start)/2;
cout<<"value of mid:"<<arr[mid]<<endl;
if(start>end) return -1;
if(arr[mid]==target){
     int left=first(arr,start,mid-1,size,target);
    return (left==-1)?mid:left;
}
if(arr[mid]>target){
    return first(arr,start,mid-1,size,target);
}
if(arr[mid]<target){
    return first(arr,mid+1,end,size,target);
}
}

int last(int *arr,int start,int end,int size,int target){
int mid=start+(end-start)/2;
cout<<"value of mid:"<<arr[mid]<<endl;
if(start>end) return -1;
if(arr[mid]==target){
     int left=first(arr,mid+1,end,size,target);
    return (left==-1)?mid:left;
}
if(arr[mid]>target){
    return first(arr,start,mid-1,size,target);
}
if(arr[mid]<target){
    return first(arr,mid+1,end,size,target);
}
}



int main(){
int arr[5]={1,2,3,3,4};
int ans=last(arr,0,4,5,3);
cout<<"answer:"<<ans<<endl;
    return 0;
}