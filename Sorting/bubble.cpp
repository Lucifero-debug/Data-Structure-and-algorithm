#include <iostream>
using namespace std;

int bubble(int arr[],int size){
int i=1;
while(i<size){
    int j=0;
    while(j<size-i){
        if(arr[j]>arr[j+1]){
           int c= arr[j+1];
           arr[j+1]=arr[j];
           arr[j]=c;
        }
        j++;
    }
    i++;
}
return 0;
}
void print(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[5]={22,4,97,65,33};
    bubble(arr,5);
    print(arr,5);
    return 0;
}