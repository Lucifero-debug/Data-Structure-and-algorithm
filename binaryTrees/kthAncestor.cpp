#include <iostream>
using namespace std;
#include <vector>

struct Node
{
	int data;
	struct Node *left, *right;
};

Node* solve(Node *root, int k, int node, vector<int>&ans) {
   if(root==NULL){
       return NULL;
   }
   if(root->data==node){
     return root;
   }
   Node* left=solve(root->left,k,node,ans);
       Node* right=solve(root->right,k,node,ans);
     if(left!=NULL && right==NULL){ 
         ans.push_back(root->data);
         return left;
         
     }
      else if(left==NULL && right!=NULL){
       ans.push_back(root->data);
      return right;
}
     
       else return NULL;
}

int kthAncestor(Node *root, int k, int node) {
  vector<int>ans;
  int result=-1;
  Node* temp=solve(root,k,node,ans);
  if(k<=ans.size()){
   result = ans[k-1];
  }
  return result;
}

int main(){
    return 0;
}