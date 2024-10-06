#include <iostream>
using namespace std;

int merge(int arr1[],int m,int arr2[],int n,int arr3[]){
    int b=0,i=0,j=0;
    while(i<m &&j<n){
        if(arr1[i]<arr2[j]){
            arr3[b]=arr1[i];
            b++;
            i++;
        }
        else{
            arr3[b]=arr2[j];
            b++;
            j++;
        }
    }
    while(i<m){
        arr3[b]=arr1[i];
        i++;
        b++;
    }
    while(j<n){
        arr3[b]=arr2[j];
        j++;
        b++;
    }
    return 0;
}

void print(int arr[],int size){
     for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr1[5]={1,3,5,7,9};
    int arr2[5]={2,4,6,8,10};
    int arr3[10]={0};
   merge(arr1,5,arr2,5,arr3);
    print(arr3,10);
    return 0;
}