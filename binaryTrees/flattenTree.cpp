#include <iostream>
using namespace std;

 class TreeNode {
    public:
     int val;
     TreeNode *left;
     TreeNode *right;
 
 };

   void flatten(TreeNode* root) {
       TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left){
                TreeNode* pred=curr->left;
                while(pred->right){
                    pred=pred->right;
                }
                pred->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }

int main(){
    return 0;
}