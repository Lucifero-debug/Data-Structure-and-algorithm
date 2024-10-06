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

void print(Node* &head){
    Node *temp=head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void insertAtHead(Node* &head,int d){
    if(head==NULL){
Node* temp=new Node(d);
temp=head;
    }
Node* temp=new Node(d);
temp ->next =head;
head=temp;
}

void reverse(Node* &head){
Node* curr=head;
Node* prev=NULL;
Node* forward=NULL;
while(curr!=NULL){
    forward=curr->next;
    curr->next=prev;
    prev=curr;
    curr=forward;
}
head=prev;
}
Node* recReverse(Node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
Node* forward=head->next;
Node* chotaHead=recReverse(forward);
head->next->next=head;
head->next=NULL;
return chotaHead;
}

int main(){
 Node* node1=new Node(10);
  Node* head=node1;
insertAtHead(head,15);
insertAtHead(head,24);
insertAtHead(head,67);
insertAtHead(head,37);
insertAtHead(head,97);
cout<<"before"<<endl;
print(head);
Node* res=recReverse(head);
cout<<"after"<<endl;
print(res);
    return 0;
}