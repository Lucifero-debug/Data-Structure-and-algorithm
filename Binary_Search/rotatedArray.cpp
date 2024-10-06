#include <iostream>
using namespace std;

int rotated(int arr[],int size){
    int start=0;
    int end=size-1;
    while (start<=end)
    {
    int mid=start+(end-start)/2;
    int next=(mid+1)%size;
    int prev=(mid+size-1)%size;
    if(arr[mid]<arr[next] && arr[mid]<arr[prev]){
        return mid;
    }
    else if(arr[mid]>arr[start]){
        start=mid+1;
    }
    else if(arr[mid]<arr[end]){
        end=mid-1;
    }
    }
return -1;
}
int binarySearch(int arr[],int star,int en,int key){
int start=star;
int end = en;
int mid=start+(end-start)/2;
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
    mid=start+(end-start)/2;
}
return -1;
}
int search(int arr[],int size,int key){
    int final=0;
    int min=rotated(arr,size);
    cout<<"min:"<<min<<endl;
    if(arr[min]==key){
        return min;
    }
     int result1 = binarySearch(arr, 0, min - 1, key);
    if (result1 != -1) {
        return result1;
    }

    int result2 = binarySearch(arr, min, size - 1, key);
    return result2;
}


int main(){
int arr[5]={3,4,5,1,2};
int res=search(arr,5,2);
cout<<"value:"<<res<<endl;
    return 0;
}