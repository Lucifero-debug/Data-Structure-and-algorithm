#include <iostream>
using namespace std;

#include <algorithm>

 class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
class info{
    public:
    int maxi;
    int mini;
    bool isBst;
    int size;
};

info solve(TreeNode *root, int &ans) {
    if (root == NULL) return info{INT_MIN,INT_MAX,true,0};
    info left=solve(root->left,ans);
    info right=solve(root->right,ans);

    info currNode;
    currNode.size=left.size+right.size+1;
    currNode.maxi=max(root->data,right.maxi);
    currNode.mini=min(root->data,left.mini);
    if(left.isBst&&right.isBst&&(root->data>left.maxi && root->data<right.mini)){
        currNode.isBst=true;
    }else{
        currNode.isBst=false;
    }

    //answer update

    if(currNode.isBst){
  ans=max(ans,currNode.size);
    }
return currNode;
}
int largestBST(TreeNode * root){
    // Write your code here.
   int maxSize=0;
   info temp=solve(root,maxSize);
 return maxSize;
}

int main(){
    return 0;
}