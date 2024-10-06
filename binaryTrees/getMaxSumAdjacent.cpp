#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

  pair<int,int>solve(Node* root){
        if(root==NULL){
        pair<int,int>p=make_pair(0,0);  //first include second exclude
        return p;    
        }
        pair<int,int>left=solve(root->left);
        pair<int,int>right=solve(root->right);
        pair<int,int>ans;
        ans.first=root->data+left.second+right.second;
        ans.second=max(left.first,left.second)+max(right.first,right.second);
        return ans;
    }
    int getMaxSum(Node *root) 
    {
        // Add your code here
        pair<int,int>ans=solve(root);
       return max(ans.first,ans.second);
        
    }

int main(){
    return 0;
}