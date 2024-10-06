#include <iostream>
using namespace std;
#include <vector>

class BinaryTreeNode {
    public : 
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};

void inOrder(BinaryTreeNode* root, vector<int>&ans){
if(root==NULL) return;
inOrder(root->left,ans);
ans.push_back(root->data);
inOrder(root->right,ans);
}

bool twoSumInBST(BinaryTreeNode* root, int target) {
	//Write your code here
    vector<int>ans;
    inOrder(root,ans);
    int end=ans.size()-1;
   int start=0;
while(start<end){
    if(target>ans[start]+ans[end]){
    start++;
    }
    else if(target<ans[start]+ans[end]){
end--;
    }
    else{
        return true;
    }
}
return false;
}

int main(){
    return 0;
}