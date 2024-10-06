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

TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    // Write your code here.
    while(root!=NULL){
        if(root->data<P->data&&root->data<Q->data){
            root=root->right;
        }
        else if(root->data>P->data&&root->data>Q->data){
            root=root->left;
        }
        else{
            return root;
        }
    }
}

int main(){
    return 0;
}