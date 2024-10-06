#include <iostream>
using namespace std;
#include <vector>

class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

//APPROACH 1
// void inOrder(TreeNode *root, vector<int> &ans) {
//   if (root == NULL)
//     return;
//   inOrder(root->left, ans);
//   ans.push_back(root->data);
//   inOrder(root->right, ans);
// }
// vector<int>merge(vector<int> ans1,vector<int> ans2){
//     int i=0,j=0;
//     vector<int>main;
//     while(i<ans1.size() && j<ans2.size()){
//         if(ans1[i]<ans2[j]){
// main.push_back(ans1[i]);
// i++;
//         }else{
//             main.push_back(ans2[j]);
//             j++;
//         }
//     }
//     while(i<ans1.size()){
//      main.push_back(ans1[i]);
// i++;   
//     }
//     while(j<ans2.size()){
//       main.push_back(ans2[j]);
//             j++;   
//     }
//     return main;
// }

// vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
// {
//     // Write your code here.
//     vector<int>ans1;
//     vector<int>ans2;
//     inOrder(root1, ans1);
//     inOrder(root2, ans2);
//     vector<int>ans=merge(ans1,ans2);
//     return ans;
// }

//APPROACH 2
void convertIntoLL(TreeNode* root,TreeNode* &head){
    if(root==NULL){
        return;
    }
    convertIntoLL(root->right, head);
    root->right=head;
    if(head!=NULL){
        head->left=root;
    }
    head=root;
    convertIntoLL(root->left, head);
}

TreeNode* merge(TreeNode* head1,TreeNode* head2){
TreeNode* head=NULL;
TreeNode* tail=NULL;

while(head1!=NULL && head2!=NULL){
if(head1->data<head2->data){
//push head1 in answer
if(head==NULL){
//first element to push
head=head1;
tail=head1;
head1=head1->right;
}else{
   tail->right=head1;
   head1->left=tail;
   tail=head1;
   head1=head1->right;
}
}else{
//push head2 in answer
if(head==NULL){
    //first element to push
head=head2;
tail=head2;
head2=head2->right;
}else{
tail->right=head2;
head2->left=tail;
tail=head2;
head2=head2->right;
}
}
}
while(head1!=NULL){
//push head1 in answer
   tail->right=head1;
   head1->left=tail;
   tail=head1;
   head1=head1->right;
}

while(head2!=NULL){
tail->right=head2;
head2->left=tail;
tail=head2;
head2=head2->right;
}
return head;   
}

int count(TreeNode* head){
    int cnt=0;
    TreeNode* temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->right;
    }
    return cnt;
}

TreeNode* listToBst(TreeNode* &head,int n){
//base case 
if(n<=0 || head==NULL){
    return NULL;
}
TreeNode* left=listToBst(head->left, n/2);
TreeNode* root=head;
root->left=left;
head=head->right;
root->right=listToBst(head, n-n/2-1);
return root;
}

vector<int>* mergeBST(TreeNode *root1, TreeNode *root2)
{
   //step1:- convert bst into sorted linked list
 TreeNode* head1=NULL;
 convertIntoLL(root1,head1);
 head1->left=NULL;
 TreeNode* head2=NULL;
 convertIntoLL(root2,head2);
 head2->left=NULL;
   //step2:- merge 2 sorted linked list
   TreeNode* head=merge(head1,head2);
   //step 3:- convert sorted linked list to bst
   listToBst(head,count(head));
}

int main(){
    return 0;
}