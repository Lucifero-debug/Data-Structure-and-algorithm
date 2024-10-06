#include <iostream>
using namespace std;
#include <queue>
#include <map>
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* createMapping(Node* root,int target,  map<Node*,Node*>&NodeToParent){
      Node* res=NULL;
      
      queue<Node*>q;
      q.push(root);
      while(!q.empty()){
          Node* front=q.front();
          q.pop();
          if(front->data==target){
              res=front;
          }
          if(front->left){
              NodeToParent[front->left]=front;
              q.push(front->left);
          }
          if(front->right){
              NodeToParent[front->right]=front;
              q.push(front->right);
          }
      }
      return res;
  }
  int burnTree(Node* root,Node* targetNode,map<Node*,Node*>NodeToParent){
      map<Node*,bool>visited;
      queue<Node*>q;
      
      q.push(targetNode);
      visited[targetNode]=true;
      int ans=0;
      while(!q.empty()){
          bool flag=0;
          int size=q.size();
          for(int i=0;i<size;i++){
              //process neighbouring nodes
              Node* front=q.front();
              q.pop();
              if(front->left&&!visited[front->left]){
                  flag=1;
                  q.push(front->left);
                  visited[front->left]=1;
              }
               if(front->right&&!visited[front->right]){
                  flag=1;
                  q.push(front->right);
                  visited[front->right]=1;
              }
              if(NodeToParent[front] && !visited[NodeToParent[front]]){
                  flag=1;
                  q.push(NodeToParent[front]);
                  visited[NodeToParent[front]]=1;
              }
          }
          if(flag==1){
              ans++;
          }
      }
      return ans;
  }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        //algo
        //step 1:- create nodeToParent maping
        //step 2:-find target Node
        //step 3:-burn the tree in min time
        map<Node*,Node*>NodeToParent;
        Node* targetNode=createMapping(root,target,NodeToParent);
        int ans=burnTree(root,targetNode,NodeToParent);
        return ans;
    }

int main(){
    return 0;
}