#include <iostream>
using namespace std;

int merge(int arr1[],int m,int arr2[],int n){

for(int i=m+n-1,j=0;i>=m,j<n;i--,j++){
    arr1[i]=arr2[j];
}

for(int i=0;i<m+n-1;i++){
   for(int j=i+1;j<m+n;j++){
    if(arr1[i]>arr1[j]){
        int c=arr1[i];
        arr1[i]=arr1[j];
        arr1[j]=c;
    }
   }
}
return 0;
}
void print(int arr[],int size){
     for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr1[6]={4,9,13,0,0,0};
    int arr2[3]={2,5,65};
    merge(arr1,3,arr2,3);
    print(arr1,6);
    return 0;
}