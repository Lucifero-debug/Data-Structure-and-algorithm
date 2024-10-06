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

 int height(struct Node* node){
        // code here 
        if(node==NULL){
            return 0; //base case
        }

        //left ki height nikali
        int left=height(node->left);
        //right ki height nikali;
        int right=height(node->right);
        int ans=max(left,right) + 1;
        return ans;
    }

int main(){

    return 0;
}
