#include <iostream>
using namespace std;
#include <vector>

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

void solve(Node* root,vector<int>&ans,int level){
    if(root==NULL){
        return;
    }
    if(level==ans.size()){
        ans.push_back(root->data);
    }
    solve(root->left,ans,level+1);
    solve(root->right,ans,level+1);
}
vector<int> leftView(Node *root)
{
   // Your code here
       vector<int>ans;
       int level=0;
       solve(root,ans,level);
       return ans;
}

void solves(Node* root,vector<int>&ans,int level){
    if(root==NULL){
        return;
    }
    if(level==ans.size()){
        ans.push_back(root->data);
    }
    solves(root->right,ans,level+1);
    solves(root->left,ans,level+1);
}
    vector<int> rightView(Node *root)
    {
       // Your Code here
         vector<int>ans;
       int level=0;
       solves(root,ans,level);
       return ans;
    }

int main(){

    return 0;
}