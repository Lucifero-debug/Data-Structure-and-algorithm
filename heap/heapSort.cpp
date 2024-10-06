#include <iostream>
using namespace std;

void heapify(int *arr,int n,int i){
int largest=i;
int left=2*i;
int right=2*i+1;
if(left<=n && arr[largest]<arr[left]){
    largest=left;
}
if(right<=n && arr[largest]<arr[right]){
    largest=right;
}
if(largest!=i){
int c=arr[largest];
arr[largest]=arr[i];
arr[i]=c;
heapify(arr,n,largest);
}
}

void heapSort(int arr[],int n){

int t=n;
while(t>1){
    //step 1:=interchange first and last
    int c=arr[1];
    arr[1]=arr[t];
    arr[t]=c;
    //step 2
    t--;
    //step 3
    heapify(arr,t,1);
}

}

int main(){
int arr[6]={-1,54,53,55,52,50};
int n=5;
for(int i=n/2;i>0;i--){
heapify(arr,n,i);
}
cout<<"printing the array first"<<endl;
for(int i=1;i<=n;i++){
    cout<<arr[i]<<" ";
}cout<<endl;
//heapsort
heapSort(arr,n);
cout<<"printing the array second"<<endl;
for(int i=1;i<=n;i++){
    cout<<arr[i]<<" ";
}cout<<endl;

    return 0;
}