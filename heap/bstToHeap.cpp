#include <iostream>
using namespace std;
#include <vector>

struct Node {
    int data;
    Node *left, *right;
};

 void inorder(Node* root,vector<int>&a){
      if(root==NULL) return;
      inorder(root->left,a);
      a.push_back(root->data);
      inorder(root->right,a);
  }
void  fillPostorder(Node* root,vector<int>&a,int &i){
      if(root==NULL) return;
      fillPostorder(root->left,a,i);
      fillPostorder(root->right,a,i);
      root->data=a[i++];
  }
  
    void convertToMaxHeapUtil(Node* root)
    {
        // Your code goes here
      vector<int>a;
      inorder(root,a);
      int i=0;
     fillPostorder(root,a,i); 
    }    

int main(){
    return 0;
}