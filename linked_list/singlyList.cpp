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

bool isLoop(Node* &head){
if(head==NULL) return false;
Node* fast=head;
Node* slow=head;
while(slow!=NULL && fast!=NULL){
    fast=fast->next;
    if(fast!=NULL){
        fast=fast->next;
    }
    slow=slow->next;
    if(slow==fast) return true;
}
return false;
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
temp->next=NULL;
delete temp;
}

void insertAtTail(Node* &tail,int d){
    if(tail==NULL){
        Node* temp=new Node(d);
        tail=temp;
    }
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}
void inserAtPositin(Node* &head,Node* tail,int d,int pos){
    if(pos==1){
        insertAtHead(head,d);
        return;
    }
Node* temp=head;
int cnt=1;
while(cnt<pos-1){
    temp=temp->next;
    cnt++;
}
if(temp->next==NULL){
    insertAtTail(tail,d);
    return;
}

//creating node for d
Node* nodeToInsert=new Node(d);
nodeToInsert->next=temp->next;
temp->next=nodeToInsert;
}

bool isCircular(Node* &head){
    if(head==NULL) return 0;
    Node* temp=head->next;
    while(temp!=NULL){
if(temp==head) return true;
temp=temp->next;
    }
    return false;
}

void print(Node* &head){
    Node *temp=head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}



int main(){

    Node* node1=new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

    Node* head=node1;
    Node* tail=node1;
    // print(head);
    insertAtTail(tail,12);
    // print(head);
    insertAtTail(tail,15);
    // print(head);
    insertAtTail(tail,23);
    // print(head);
    inserAtPositin(head,tail,55,2);
    // print(head);
//  deleteNode(head,2);
    // print(head);
    //  if(isLoop(head)){
    //     cout<<"Loop found"<<endl;
    //   }
    //   else{
    //     cout<<"Loop not found"<<endl;
    //   }
print(head);
    
    return 0;
}