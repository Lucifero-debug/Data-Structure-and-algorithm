#include <iostream>
using namespace std;
#include <queue>

class Tree{
    public:
    int val;
    Tree* left;
    Tree* right;

    Tree(int d){
        this->val=d;
        this->left=NULL;
        this->right=NULL;
    }
};

void levelOrderTraversal(Tree* root){
       queue<Tree*>q;
       q.push(root); 
       q.push(NULL);
       while (!q.empty())
       {
        Tree* temp=q.front();
        q.pop();

        if(temp==NULL){
            //purana level complete traverse
            cout<<endl;
            if(!q.empty()){
                //queue still has some child nodes
                q.push(NULL);
            }
        }else{
            cout<<temp->val<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
       }
       
    }

Tree* insertIntoBST(Tree* &root,int d){
if(root==NULL){
    root=new Tree(d);
    return root;
}
else if(d>root->val){
 root->right=insertIntoBST(root->right,d);
}
else if(d<root->val){
     root->left=insertIntoBST(root->left,d);
}
return root;
}

Tree* max(Tree* root){
Tree* temp=root;
while(temp->right!=NULL){
    temp=temp->right;
}
return temp;
}



Tree* deleteNode(Tree* &root,int x){
if(root==NULL){
    return NULL;
}
//case of delete
else if(root->val==x){
//no child
if(root->left==NULL && root->right==NULL){
Tree* temp=root;
delete root;
return NULL;
}
//one child
if(root->left!=NULL && root->right==NULL){
Tree* temp=root->left;
delete root;
return temp;
}
if(root->left==NULL && root->right!=NULL){
Tree* temp=root->right;
delete root;
return temp;
}
//two child
if(root->left!=NULL && root->right!=NULL){
int maxi=max(root->left)->val;
root->val=maxi;
root->left=deleteNode(root->left,maxi);
return root;
}
}
else if(root->val>x){
    root->left=deleteNode(root->left,x);
}
else{
    root->right=deleteNode(root->right,x);
}
return root;
}

int main(){
Tree* root=NULL;
insertIntoBST(root,7);
insertIntoBST(root,9);
insertIntoBST(root,5);
insertIntoBST(root,10);
levelOrderTraversal(root);
deleteNode(root,9);
levelOrderTraversal(root);
    return 0;
}