#include <iostream>
using namespace std;

int search(int arr[],int size,int key){
int start=0;
int end = size - 1;
int mid=start+(end-start/2);
while(start<=end){
    if(arr[mid]==key){
        return mid;
    }
    else if(key>arr[mid]){
        start=mid+1;
    }
    else if(key<arr[mid]){
        end=mid-1;
    }
    mid=start+(end-start/2);
}
return -1;
}
int first(int arr[],int size,int key){
int start=0;
int end=size-1;
int mid=start+(end-start/2);
int ans=-1;
while (start<=end)
{
if(arr[mid]==key){
    ans=mid;
    end=mid-1;
}
else if(arr[mid]<key){
    start=mid+1;
}
else if(arr[mid]>key){
    end=mid-1;
}
mid=start+(end-start/2);
}
return ans;
}

int last(int arr[],int size,int key){
int start=0;
int end=size-1;
int mid=start+(end-start/2);
int ans=-1;
while (start<=end)
{
if(arr[mid]==key){
    ans=mid;
    start=mid+1;
}
else if(arr[mid]<key){
    start=mid+1;
}
else if(arr[mid]>key){
    end=mid-1;
}
mid=start+(end-start/2);
}
return ans;
}

int count(int arr[],int size,int key){
    int firstoccur=first(arr,size,key);
    int lastoccur=last(arr,size,key);
    int counts=lastoccur-firstoccur+1;
    return counts;
}

int main(){
    int arr[5]={0,1,1,3,3};
int res=count(arr,5,3);
cout<<"answer is:"<<res<<endl;
return 0;
}