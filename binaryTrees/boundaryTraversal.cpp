#include <iostream>
using namespace std;
#include <vector>

struct Node
{
    int data;
    Node* left, * right;
};

void left(Node *root,vector<int>&ans){
    if(root==NULL || root->left==NULL && root->right==NULL){
        return;
    }
    ans.push_back(root->data);
    if(root->left){
        left(root->left,ans);
    }else{
        left(root->right,ans);
    }
}
void leaf(Node* root,vector<int>&ans){
  if(root==NULL){
      return;
  }  
  if(root->left==NULL && root->right==NULL){
      ans.push_back(root->data);
      return;
  }
 leaf(root->left,ans);
 leaf(root->right,ans);
}

void right(Node* root,vector<int>&ans){
     if(root==NULL || root->left==NULL && root->right==NULL){
        return;
    }
    if(root->right){
        right(root->right,ans);
    }else{
        right(root->left,ans);
    }
    ans.push_back(root->data);
}
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        ans.push_back(root->data);
        //traverse left part
        left(root->left,ans);  
        //traverse leaf nodes
        leaf(root->left,ans);
        leaf(root->right,ans);
        //traverse right from reverse
        right(root->right,ans);
        return ans;
    }


int main(){
    return 0;
}