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

void count(Tree *root,int &cnt){
  if(root->left==NULL && root->right==NULL){
        cnt++;
        return;
    }
   count(root->left,cnt);
    count(root->right,cnt);
}
int noOfLeafNodes(Tree *root){
    // Write your code here.
    int cnt=0;
count(root,cnt);
  return cnt; 
}

int main(){
    return 0;
}