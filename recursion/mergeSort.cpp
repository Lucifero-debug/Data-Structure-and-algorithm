#include <iostream>
using namespace std;

void merge(int *arr,int s,int e){
    int mid=s+(e-s)/2;
   int len1=mid-s+1;
   int len2=e-mid;
   int *first= new int[len1];
   int *second= new int[len2];


//copy values
   int mainIndex=s;
   for(int i=0;i<len1;i++){
    first[i]=arr[mainIndex++];
   }
    mainIndex=mid+1;
   for(int i=0;i<len2;i++){
    second[i]=arr[mainIndex++];
   }

   //merge 2 sorted arrays
   int index1=0;
   int index2=0;
   mainIndex=s;
   while(index1<len1 && index2<len2){
    if(first[index1]<second[index2]){
    arr[mainIndex++]=first[index1++];
    }
    else{
        arr[mainIndex++]=second[index2++];
    }
   }
   while(index1<len1){
    arr[mainIndex++]=first[index1++];
   }
   while(index2<len2){
    arr[mainIndex++]=second[index2++];
   }
}

void mergeSort(int *arr,int s,int e){
    if(s>=e) return;
    int mid=s+(e-s)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,e);
}

void print(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }
}

int main(){
    int arr[5]={78,22,34,12,96};
    mergeSort(arr,0,4);
    print(arr,5);
    return 0;
}