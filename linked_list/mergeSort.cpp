#include <iostream>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }

     ~Node() {
        int value = this -> data;
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

void insertAtHead(Node* &head,int d){
    if(head==NULL){
Node* temp=new Node(d);
temp=head;
    }
Node* temp=new Node(d);
temp ->next =head;
head=temp;
}

void print(Node* &head){
    Node *temp=head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* getMid(Node* head){
    if(head==NULL) return head;
    Node* slow=head;
    Node* fast=head->next;
    while(fast->next!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast->next!=NULL) fast=fast->next;
        slow=slow->next;
    }
    return slow; 
}

Node* merge(Node* left,Node* right){
    if(left==NULL) return right;
    if(right==NULL) return left;
    Node* dummy=new Node(-1);
    Node* ans=dummy;
    while(left!=NULL && right!=NULL){
        if(left->data<=right->data){
           ans->next=left;
            ans=ans->next;
            left=left->next;
        }else{
           ans->next=right;
            ans=ans->next;
            right=right->next;
        }
    }
    while(left!=NULL){
           ans->next=left;
            ans=ans->next;
            left=left->next;  
    }
    while(right!=NULL){
           ans->next=right;
            ans=ans->next;
            right=right->next;
    }
   Node* hate=dummy->next;
   return hate;
}

Node* mergeSort(Node* &head){
    if(head==NULL || head->next==NULL) return head;
    Node* mid=getMid(head);
    Node* left=head;
    Node* right=mid->next;
    mid->next=NULL;
    left=mergeSort(left);
    right=mergeSort(right);
    Node* ans=merge(left,right);
    return ans;
}

int main(){

  Node* node=new Node(65);
   Node* head=node;
    insertAtHead(head,12);
    insertAtHead(head,22);
    insertAtHead(head,78);
    insertAtHead(head,99);
print(head);
Node* ans= mergeSort(head);
print(ans);
    return 0;
}