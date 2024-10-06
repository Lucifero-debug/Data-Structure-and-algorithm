#include <iostream>
using namespace std;

int floor(int arr[],int key,int size){
   int start=0;
   int end=size-1;
   int mid=start+(end-start)/2;
   int ans=0;
   while(start<=end){
    if (arr[mid]==key)
    {
   return mid;
    }
    else if(arr[mid]<key){
        ans=mid;
        start=mid+1;
    }
    else if(arr[mid]>key){
        end=mid-1;
    }
    mid=start+(end-start)/2;
   }
   return arr[ans];
}

int ceil(int arr[],int key,int size){
   int start=0;
   int end=size-1;
   int mid=start+(end-start)/2;
   int ans=0;
   while(start<=end){
    if (arr[mid]==key)
    {
   return mid;
    }
    else if(arr[mid]<key){
        start=mid+1;
    }
    else if(arr[mid]>key){
        ans=mid;
        end=mid-1;
    }
    mid=start+(end-start)/2;
   }
   return arr[ans];
}

int main(){
    int arr[5]={1,2,3,5,6};
    int res= ceil(arr,4,5);
    cout<<"value:"<<res<<endl;
    return 0;
}