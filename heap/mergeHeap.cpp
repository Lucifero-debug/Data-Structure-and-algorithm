#include <iostream>
using namespace std;
#include <vector>

  void heapify(vector<int>&c,int i,int n){
      int largest=i;
      int left=2*i+1;
      int right=2*i+2;
      if(left<n&&c[largest]<c[left]){
         largest=left;
      }
      if(right<n&&c[largest]<c[right]){
          largest=right;
      }
     if(largest!=i){
         swap(c[largest],c[i]);
         heapify(c,largest,n);
     }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
      //step 1:- merge a and b
     vector<int> c = a;  // Start with all elements of a
        c.insert(c.end(), b.begin(), b.end()); 
        int size=m+n;
        //step 2:build heap array
       for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(c, i, size);
        }
        return c;
    }

int main(){

    return 0;
}