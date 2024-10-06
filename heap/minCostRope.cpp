#include <iostream>
using namespace std;
#include <vector>
#include <queue>

long long minCost(vector<long long>& arr) {
        // Your code here
        priority_queue<int, vector<int>, greater<int>>q;
        for(int i=0;i<arr.size();i++){
            q.push(arr[i]);
        }
        long long sum=0;
         while (q.size() > 1) {
            // Extract the two smallest elements
            long long first = q.top();
            q.pop();
            long long second = q.top();
            q.pop();

            // Calculate the cost of combining them
            long long cost = first + second;
            sum += cost;

            // Push the combined element back into the heap
            q.push(cost);
        }

        return sum;
    }

int main(){
    return 0;
}