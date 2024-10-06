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

  pair<bool,int> balancedFast(Node* root){
        if(root==NULL){
       pair<bool,int>p=make_pair(true,0);
       return p;
        }
        pair<bool,int>left=balancedFast(root->left);
        pair <bool,int>right=balancedFast(root->right);
        bool op1=left.first;
        bool op2=right.first;
        bool op3=left.second-right.second<=1;
        
        pair<bool,int>ans;
        if(op1&&op2&&op3){
            ans.first=true;
            ans.second=max(left.second,right.second)+1;
        }else{
            ans.first=false;
            ans.second=max(left.second,right.second)+1;
        }
        return ans;
     }
    bool isBalanced(Node *root)
    {
        //  Your Code here
        return balancedFast(root).first;
       
    }

int main(){
    return 0;
}