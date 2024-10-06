#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node* left;
  Node* right;
  Node(int data){
    this->data=data;
  }
};

  int find(int in[],int element,int n){
        for(int i=0;i<n;i++){
         if(in[i]==element){
             return i;
         }
        }
             return -1;
    }
    Node* solve(int in[],int pre[], int n,int &index,int startIn,int endIn){
        if(index>=n || startIn>endIn){
            return NULL;
        }
        int element=pre[index++];
        Node* root=new Node(element);
        int position=find(in,element,n);
        
        root->left=solve(in,pre,n,index,startIn,position-1);
        root->right=solve(in,pre,n,index,position+1,endIn);
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code her\]
        int preOrderIndex=0;
        Node* ans=solve(in,pre,n,preOrderIndex,0,n-1);
        return ans;
    }

      int finds(int in[],int element,int n){
        for(int i=0;i<n;i++){
         if(in[i]==element){
             return i;
         }
        }
             return -1;
    }
    Node* solves(int in[],int post[], int n,int &index,int startIn,int endIn){
        if(index<0 || startIn>endIn){
            return NULL;
        }
        int element=post[index--];
        Node* root=new Node(element);
        int position=finds(in,element,n);
        
        root->right=solves(in,post,n,index,position+1,endIn);
        root->left=solves(in,post,n,index,startIn,position-1);
        return root;
    }
    Node *buildTrees(int n, int in[], int post[]) {
        // Your code here
        int postOrderIndex=n-1;
        Node* ans=solves(in,post,n,postOrderIndex,0,n-1);
        return ans;
    }

int main(){
    return 0;
}