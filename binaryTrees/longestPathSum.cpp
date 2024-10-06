#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

pair<int,int>solve(Node* root,int sum,int length,pair<int,int>&maxi){
        if(root==NULL){
            pair<int,int>p=make_pair(0,0);
            return p;
        }
        sum+=root->data;
         pair<int,int>p;
        if( root->left==NULL && root->right==NULL){
        if(length>maxi.second || (length == maxi.second && sum > maxi.first)){
            maxi={sum,length};
        }
        }
        if(root->left){
            solve(root->left,sum,length+1,maxi);
        }
        if(root->right){
            solve(root->right,sum,length+1,maxi);
        }
        return maxi;
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
           pair<int, int> maxi = {0, 0};
      return  solve(root,0,0,maxi).first;
    }

int main(){
    return 0;
}