#include <iostream>
using namespace std;
#include <queue>

 int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> pq;
        
        //step 1 create max heap for first k elements
        for(int i=0;i<k;i++){
            pq.push(arr[i]);
        }
        //step 2:-for rest if element<heap.top()=>heap.pop() and heap.push(element)
        for(int i=k;i<arr.size();i++){
            if(arr[i]<pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
    }

int main(){
return 0;
}