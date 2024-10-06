#include <iostream>
using namespace std;

bool isValid(int n,int arr[],int size){
int student=1;
int page=0;
for (int i = 0; i < size; i++)
{
    page=page+arr[i];
    if(page>n){
        student++;
        page=arr[i];
    }
if (student>2)
{
    return false;
}
}
return true;
}
int book(int arr[]){
     int start=0;
    int sum =0;
    int answer=0;
    for (int i = 0; i < 4; i++)
    {
     sum=sum+arr[i];
    }
    int end = sum;
    while(start<=end){
        int mid = (start+end)/2;
        if(isValid(mid,arr,4)){
        answer=mid;
            end=mid-1;
        }
        else{
        start=mid+1;
        }
    }
    return answer;
}

int main(){
    int arr[4]={20,35,60,84};
   int res= book(arr);
   cout<<"value:"<<res<<endl;
    return 0;
}