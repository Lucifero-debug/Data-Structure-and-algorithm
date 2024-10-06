#include <iostream>
using namespace std;

int reverse(int arr[],int size){
int i=0,j=size-1;
while(i<=j){
   int c= arr[i];
   arr[i]=arr[j];
   arr[j]=c;
   i++;
   j--;
}
return 0;
}
void print(int arr[],int size){
     for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[5]={1,2,3,4,5};
    reverse(arr,5);
    print(arr,5);
    return 0;
}