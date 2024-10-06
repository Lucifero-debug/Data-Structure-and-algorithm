#include <iostream>
using namespace std;

int selection(int arr[],int size){
for(int i=0;i<size-1;i++){
    // int min=arr[i];
    for (int j = i+1; j < size; j++)
    {
        if (arr[i]>arr[j]){
            int c=arr[i];
            arr[i]=arr[j];
            arr[j]=c;
        }
    }
}
return 0;
}

int print(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

int main(){
int arr[5]={2,72,55,95,23};
selection(arr,5);
cout<<"sorted array"<<endl;
print(arr,5);
return 0;
}