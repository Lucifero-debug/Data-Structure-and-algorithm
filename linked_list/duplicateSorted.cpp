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

//code for removing duplicated from sorted linked list

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

void duplicate(Node* &head){
Node* temp=head;
Node* misc=NULL;

while(temp!=NULL && temp->next!=NULL){
    if(temp->data==temp->next->data){
   misc=temp->next;
   temp->next=misc->next;
   misc->next=NULL;
   delete misc;
    }
    else{
    temp=temp->next;
    }
}
}

int main(){

  Node* node1=new Node(3);
   Node* head=node1;
   insertAtHead(head,2);
   insertAtHead(head,2);
   insertAtHead(head,2);
   insertAtHead(head,1);
   print(head);
duplicate(head);
   print(head);


    return 0;
}