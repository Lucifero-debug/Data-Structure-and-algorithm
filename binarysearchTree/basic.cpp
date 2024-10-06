#include <iostream>
using namespace std;
#include <queue>

class Node{
public:
int val;
Node* left;
Node* right;

Node(int d){
    this->val=d;
    this->left=NULL;
    this->right=NULL;
}
};

 void levelOrderTraversal(Node* root){
       queue<Node*>q;
       q.push(root); 
       q.push(NULL);
       while (!q.empty())
       {
        Node* temp=q.front();
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

Node* insertIntoBST(Node* &root,int d){
if(root==NULL){
    root=new Node(d);
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

bool search(Node* root,int d){
 Node* temp=root;
  while(temp!=NULL){
      if(temp->val==d){
          return true;
      }
     else if(d>temp->val){
          temp=temp->right;
      }
      else if(d<temp->val){
          temp=temp->left;
      }
  }
  return false;
}

int main(){
    Node* root=NULL;
    insertIntoBST(root,23);
    levelOrderTraversal(root);
    insertIntoBST(root,56);
    insertIntoBST(root,17);
    levelOrderTraversal(root);
    bool ans=search(root,5);
    cout<<"answer"<<ans<<endl;
    return 0;
}