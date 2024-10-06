#include <iostream>
using namespace std;

void spiral(int arr[][3]){
int starRow=0,startCol=0,endingRow=2,endingCol=2;
int count=0,total=9;
while(count<=9){
    for(int i=startCol;i<=endingCol;i++){
        cout<<arr[starRow][i]<<endl;
        count++;
    }
        starRow++;
    for(int i=starRow;i<=endingRow;i++){
        cout<<arr[i][endingCol]<<endl;
        count++;
    }
        endingCol--;
    for(int i=endingCol;i>=startCol;i--){
        cout<<arr[endingRow][i]<<endl;
        count++;
    }
        endingRow--;
    for(int i=endingRow;i>=starRow;i--){
        cout<<arr[i][startCol]<<endl;
        count++;
    }
        startCol++;
}
}

int main(){
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    spiral(arr);
}