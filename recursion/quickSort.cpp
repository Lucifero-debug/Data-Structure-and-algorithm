#include <iostream>
using namespace std;

int partition(int arr[],int s,int e){
    int pivot=arr[s];
    int count=0;
for(int i=s+1;i<=e;i++){
if(pivot>=arr[i]) count++;
}
int pivotIndex=s+count;
swap(arr[s],arr[pivotIndex]);
int i=s,j=e;
while(i<pivotIndex && j>pivotIndex){
  while(arr[i]<pivot) i++;
  while(arr[j]>pivot) j--;
    if(arr[i]>pivot && arr[j]<pivot){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}
return pivotIndex;
}

void quick(int *arr,int s,int e){
if(s>=e) return;
int p=partition(arr,s,e);
quick(arr,s,p-1);
quick(arr,p+1,e);
}
void print(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }
}

int main(){
    int arr[5]={2,4,1,6,9};
    quick(arr,0,4);
    print(arr,5);
    return 0;
}