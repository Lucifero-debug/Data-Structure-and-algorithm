#include <iostream>
using namespace std;

int max(int arr[],int size){
int start=0;
int end=size-1;
while (start<=end)
{
int mid=start+(end-start)/2;
int prev=(mid+size-1)%size;
int next=(mid+1)%size;
if(arr[mid]>arr[prev] && arr[mid]>arr[next]){
    return arr[mid];
}
else if(arr[mid]<arr[prev]){
    end=mid-1;
}
else if(arr[mid]<arr[next]){
    start=mid+1;
}
// mid=start+(end-start)/2;
}
return -1;
}

int main(){
   int arr[6]={1,3,13,12,4,2};
   int res= max(arr,6);
   cout<<"value:"<<res<<endl;
   return 0;
}