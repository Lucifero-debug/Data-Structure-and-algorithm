#include <iostream>
using namespace std;

int valid(int n,int *arr,int k,int size){
int count=1;
int sum=0;
for(int i=0;i<size;i++){
if (arr[i] > n) return 0;
if(sum+arr[i]>n){
    count++;
    sum=arr[i];
if(count>k) return 0;
}else{
sum=sum+arr[i];
}
}
return 1;
}

int allo(int *arr,int start,int end,int size,int k){
   if(start>end) return -1;
   int mid=start+(end-start)/2;
   int res=valid(mid,arr,2,size);
   int ans=-1;
   if(res==1){
   ans=mid;
   int left=allo(arr,start,mid-1,size,k);
   return (left==-1)?mid:left;
   }else{
    return allo(arr,mid+1,end,size,k);
   }
}

int main(){
    int arr[4]={10,20,30,40};
     int sum=0;
    for(int i=0;i<4;i++){
        sum=sum+arr[i];
    }
    int ans= allo(arr,0,sum,4,2);
    cout<<"answer"<<ans<<endl;
    return 0;
}