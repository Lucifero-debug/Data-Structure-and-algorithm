#include <iostream>
using namespace std;

int sqt(int n){
   int start=0;
   int end=n;
   int mid=start+(end-start)/2;
   int ans=-1;
   while(start<=end){
    if(mid*mid==n){
        return mid;
    }
    else if(mid*mid<n){
      ans=mid;
      start=mid+1;
    }
else if(mid*mid>n){
    end=mid-1;
}
mid=start+(end-start)/2;
   }
return ans;
}

double precise(int n,int precision,double soln){
    double point=1.0;
  for (int i = 0; i < precision; i++)
  {
 point= point/10;
  }
  double ans=0;
while(soln*soln<=n){
ans=soln;
soln+=point;
}
return ans;
}

int main(){
double res=sqt(45);
double wait=precise(46,2,res);
cout<<"value is:"<<wait<<endl;
}