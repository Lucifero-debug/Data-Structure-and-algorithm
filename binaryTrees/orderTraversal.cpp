#include <iostream>
using namespace std;

class Tree{
    public:
    int data;
    Tree* left;
    Tree* right;

    Tree(int d){
this->data=d;
this->left=NULL;
this->right=NULL;
    }

};

 Tree* buildTree(Tree* root){
     cout<<"enter the data"<<endl;
     int data;
     cin>>data;
     root=new Tree(data);
     if(data==-1) return NULL;
     cout<<"enter data for inserting in left of"<<data<<endl;
     root->left=buildTree(root->left);
     cout<<"enter data for inserting in right of"<<data<<endl;
     root->right=buildTree(root->right);
     return root;
    }

    void inOrder(Tree* root){
        if(root==NULL) return;
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }

    void preOrder(Tree* root){
        if(root==NULL) return;
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
    void postOrder(Tree* root){
          if(root==NULL) return;
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }

//  Inorder=LNR  preorder=NLR  postorder=LRN L=left jao  R=right jao  N=print kraao 

int main(){

Tree* root=NULL;
root=buildTree(root);
postOrder(root);
    return 0;
}