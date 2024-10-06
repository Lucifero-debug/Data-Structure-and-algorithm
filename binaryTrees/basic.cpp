#include <iostream>
using namespace std;
#include <queue>
#include <stack>

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
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
       }
       
    }

    void reverseOrderTraversal(Tree* root){
      queue<Tree*>q;
      stack<Tree*>st;
      q.push(root);
      q.push(NULL);
      while(!q.empty()){
        Tree* temp=q.front();
        q.pop();
        if(temp==NULL){
            st.push(NULL);
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
        st.push(temp);
       if(temp->right) q.push(temp->right);
       if(temp->left) q.push(temp->left);
        }
      } 
      while(!st.empty()){
        Tree* ans=st.top();
        st.pop();
        if(ans==NULL){
            cout<<endl;
        }else{
            cout<<ans->data<<" ";
        }
      }
    }

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

int main(){

Tree* root=NULL;
root=buildTree(root);
reverseOrderTraversal(root);
    return 0;
}