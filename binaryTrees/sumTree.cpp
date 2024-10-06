#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

   pair<bool,int>Sum(Node* root){
        if(root==NULL){
       return make_pair(true,0);
        }
        if (root->left == NULL && root->right == NULL) {
      return make_pair(true,root->data);
    }

       pair <bool,int> left=Sum(root->left);
        pair <bool,int> right=Sum(root->right);
        bool op1=left.first;
        bool op2=right.first;
        bool op3=(root->data==left.second+right.second);
        pair<bool,int>ans;
        if(op1&&op2&&op3){
            ans.first=true;
            ans.second=root->data+left.second+right.second;
        }else{
            ans.first=false;
        }
        return ans;
   }
 
    bool isSumTree(Node* root) {
        // Your code here
    return Sum(root).first;
    }

int main(){
    return 0;
}