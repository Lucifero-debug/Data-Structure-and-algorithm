#include <iostream>
using namespace std;
#include <vector>

class TreeNode {
    public : 
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};

void inOrder(TreeNode *root, vector<int> &ans) {
  if (root == NULL)
    return;
  inOrder(root->left, ans);
  ans.push_back(root->data);
  inOrder(root->right, ans);
}

TreeNode* helper(int s,int e,vector<int>ans){
if(s>e) return NULL;
int mid=(s+e)/2;
TreeNode* temp=new TreeNode(ans[mid]);
temp->left=helper( s, mid-1, ans);
temp->right=helper(mid+1,  e, ans);
return temp;
}

TreeNode* balancedBst(TreeNode* root) {
    // Write your code here.
    //step 1:-inorder nikalo
    //step 2:-mid nikalo'
    //step 3:-mid se root banke recursion

    //step 1
    vector<int>ans;
     inOrder(root,ans);
     //step 2:-find mid
     int n=ans.size()-1;
     //step 3
    return helper(0,n,ans); 
}

int main(){
    return 0;
}