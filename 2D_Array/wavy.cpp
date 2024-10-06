#include <iostream>
using namespace std;

void wavy(int arr[][4]){
for(int col=0;col<4;col++){
    if(col==0 || col%2==0){
        for(int j=0;j<3;j++){
            cout<<arr[j][col]<<endl;
        }
    }else{
        for(int j=2;j>=0;j--){
            cout<<arr[j][col]<<endl;
        }
    }
}
}

int main(){
    
    int arr[3][4];
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }
    wavy(arr);
}