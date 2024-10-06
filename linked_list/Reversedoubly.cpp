#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data=data;
        this->prev=NULL;
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

void print(Node* &head){
    Node *temp=head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void insertAtHead(Node* &head,int d){

    if (head==NULL) //for empty list
{
    Node* temp=new Node(d);
    temp=head;
    }else{
Node* temp=new Node(d);
temp->next=head;
temp->prev=NULL;
head->prev=temp;
head=temp;
    }
}

void reverse(Node* &head){
    if(head==NULL || head->next==NULL)return;
    Node* curr=head;
    Node* prev=NULL;
    Node* forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        curr->prev=forward;
        prev=curr;
        curr=forward;
    }
    head=prev;
}

int main(){
Node* node1=new Node(15);
Node* head=node1;
insertAtHead(head,11);
insertAtHead(head,51);
insertAtHead(head,34);
insertAtHead(head,89);
insertAtHead(head,72);
cout<<"before"<<endl;
print(head);
reverse(head);
cout<<"after"<<endl;
print(head);
    return 0;
}