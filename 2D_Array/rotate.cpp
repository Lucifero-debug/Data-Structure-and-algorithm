#include <iostream>
using namespace std;

void rotate(int arr[][3]){
    int temp[3][3];
for(int i=0;i<3;i++){
    for(int j=0,m=2;j<3,m>=0;j++,m--){
    temp[i][j]=arr[m][i];
    }
}
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        cout<<temp[i][j];
    }
    cout<<endl;
}
}
int swap(int a,int b){
int c=a;
a=b;
b=c;
return 0;
}

void ratate(int arr[][3]){
for(int i=0;i<3;i++){
    for(int j=0,m=2;j<3,m>=0;j++,m--){
    int c=arr[i][j];
    arr[i][j]=arr[m][i];
    arr[m][i]=c;
    }
}
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        cout<<arr[i][j];
    }
    cout<<endl;
}
}

int main(){
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    ratate(arr);
    return 0;
}