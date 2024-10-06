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
int getLen(Node* &head){
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}

void deleteNode(Node* &head,int pos){
    if(pos==1){
        Node* temp=head;
        head=head->next;
        delete temp;
    }
    Node* temp=head;
    Node* prev=NULL;
    int cnt=1;
    while(cnt<pos){
        prev=temp;
        temp=temp->next;
        cnt++;
    }
    prev->next=temp->next;
    temp->next->prev=prev;
    temp->next=NULL;
    temp->prev=NULL;
    delete temp;
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

void inserAtTail(Node* &tail,int d){
    if(tail==NULL){
Node* temp=new Node(d);
tail=temp;
    }else{
Node* temp=new Node(d);
tail->next=temp;
temp->prev=tail;
tail=temp;
    }
}

void removeDuplicates(Node *head)
{
    if(head==NULL || head->next==NULL) return;
    Node* temp=head;
Node* misc=NULL;

while(temp!=NULL && temp->next!=NULL){
  if (temp->data == temp->next->data) {
    misc = temp->next;
    misc->next->prev=temp;
    temp->next = misc->next;
    misc->next = NULL;
    delete misc;
  }else{
  temp = temp->next;
  }
}
}


int main(){

Node* node1=new Node(3);
Node* head=node1;
Node* tail=node1;
cout<<"before"<<endl;
insertAtHead(head,2);
insertAtHead(head,2);
insertAtHead(head,2);
insertAtHead(head,1);
print(head);
removeDuplicates(head);
print(head);
// cout<<"after"<<endl;
// print(head);
// cout<<"len"<<getLen(head)<<endl;
// insertAtHead(head,5);
// insertAtHead(head,25);
// insertAtHead(head,35);
// print(head);
// cout<<"len"<<getLen(head)<<endl;
// inserAtTail(tail,89);
// print(head);
// deleteNode(head,2);
// print(head);
    return 0;
}