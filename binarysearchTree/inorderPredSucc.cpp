#include <iostream>
using namespace std;

 class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
    int succ=-1;
    int pred=-1;
    //find key
    TreeNode* target=root;
    while(target!=NULL&&target->data!=key){
        if(target->data>key){
            succ=target->data;
            target=target->left;
        }
        else{
            pred=target->data;
            target=target->right;
        }
    }
     if(target==NULL){
         return {pred,succ};
     }

    TreeNode* leftTree=target->left;
    TreeNode* rightTree=target->right;
    //predeccessor
    while(leftTree!=NULL){
        pred=leftTree->data;
        leftTree=leftTree->right;
    }
    //successor
    while(rightTree!=NULL){
        succ=rightTree->data;
        rightTree=rightTree->left;
    } 
    pair<int,int>ans=make_pair(pred,succ);
    return ans;
}

int main(){
    return 0;
}