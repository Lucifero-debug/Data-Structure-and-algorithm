#include <iostream>
using namespace std;
#include <vector>

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

 void solve(Node* root,vector<int>&ans,int &count,int k){
     if(root==NULL){
         return;
     } 
     
     ans.push_back(root->data);
     solve(root->left,ans,count,k);
     solve(root->right,ans,count,k);
     int sum=0;
    for (int i = ans.size() - 1; i >= 0; i--) { // Start from the last element
        sum += ans[i];
        if (sum == k) {
            count++;
        }
    }
     ans.pop_back();
  }
  
    int sumK(Node *root, int k) {
        // code here
      vector<int>ans;
      int count=0;
      solve(root,ans,count,k);
      return count;
    }

int main(){
    return 0;
}