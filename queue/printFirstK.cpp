#include <iostream>
#include<queue>
#include <vector>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
     vector<long long>ans;
      queue<long long>q;
      for(int i=0;i<K;i++){
          if(A[i]<0){
              q.push(A[i]);
          }
      }
      if(!q.empty()){
          ans.push_back(q.front());
      }else{
          ans.push_back(0);
      }
      
      for(int i=K;i<N;i++){
        if(!q.empty()&&A[i-K]==q.front()){
            q.pop();
        }  
        if(A[i]<0){
            q.push(A[i]);
        }
        
         if(!q.empty()){
          ans.push_back(q.front());
      }else{
          ans.push_back(0);
      }
      }
      
      return ans;
      
 }

int main(){

    return 0;
}