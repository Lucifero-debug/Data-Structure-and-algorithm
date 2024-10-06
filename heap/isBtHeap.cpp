#include <iostream>
using namespace std;
#include <queue>

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

 int countNode(struct Node* tree){
      int count=0;
     queue<Node*>q;
      q.push(tree);
      while(!q.empty()){
          Node* top=q.front();
          q.pop();
          count++;
          if(top->left){
              q.push(top->left);
          }
          if(top->right){
              q.push(top->right);
          }
      }
      return count;
  }
  
  bool isCbt(struct Node* tree,int i,int nodeCount){
      if(tree==NULL){
          return true;
      }
     if(i>=nodeCount){
         return false;
     }
          bool left=isCbt(tree->left,2*i+1,nodeCount);
          bool right=isCbt(tree->right,2*i+2,nodeCount);
          return left && right;
  }
  
  bool isMaxorder(struct Node* tree){
      if(tree==NULL){
          return true;
      }
      //leaf node
      if(tree->left==NULL && tree->right==NULL){
          return true;
      }
      //only left child
      if(tree->right==NULL){
          return tree->left->data < tree->data;
      }
      //both child present
      if(tree->left->data<tree->data && tree->right->data<tree->data){
          bool left=isMaxorder(tree->left);
          bool right=isMaxorder(tree->right);
          return left && right;
      }
      else{
          return false;
      }
  }
  
    bool isHeap(struct Node* tree) {
        // code here
        int totalCount=countNode(tree);
        if(isCbt(tree,0,totalCount) && isMaxorder(tree)){
            return true;
        }else{
            return false;
        }
    }

int main(){
    return 0;
}