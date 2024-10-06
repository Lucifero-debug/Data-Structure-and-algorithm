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

Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       if(root==NULL){
           return NULL;
       }
       if(root->data==n1 || root->data==n2){
           return root;
       }
       Node* left=lca(root->left,n1,n2);
       Node* right=lca(root->right,n1,n2);
     if(left!=NULL && right==NULL) return left;
      else if(left==NULL && right!=NULL) return right;
      else if(left!=NULL && right!=NULL) return root;
       else return NULL;

      }
    

int main(){
    return 0;
}