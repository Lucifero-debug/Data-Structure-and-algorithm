#include <iostream>
using namespace std;


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

  bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        if(r1==NULL && r2==NULL){
            return true;
        }
        if(r1==NULL && r2!=NULL){
            return false;
        }
        if(r1!=NULL && r2==NULL){
            return false;
        }
        if(r1->data==r2->data){
        bool left=isIdentical(r1->left,r2->left);
        bool right=isIdentical(r1->right,r2->right);
        return left&& right;
        }
        return false;
      
    }

int main(){
    return 0;
}