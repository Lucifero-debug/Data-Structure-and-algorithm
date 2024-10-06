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

//code to sort 0s 1s and 2s from linked list
void insertAtHead(Node* &head,int d){
    if(head==NULL){
Node* temp=new Node(d);
temp=head;
    }
Node* temp=new Node(d);
temp ->next =head;
head=temp;
}

void insertAtTail(Node* &head,Node* &curr){
    head->next=curr;
    head=curr;
}

void print(Node* &head){
    Node *temp=head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


// with replacing
void sort(Node* &head){
   int zeroCount=0;
   int oneCount=0;
   int twoCount=0;
   Node* temp=head;
 while(temp!=NULL){
    if(temp->data==0) zeroCount++;
    else if(temp->data==1) oneCount++;
    else if(temp->data==2) twoCount++;
    temp=temp->next;
 }
 temp=head;
   
   while(temp!=NULL){
    if(zeroCount!=0){
        temp->data=0;
        temp=temp->next;
        zeroCount--;
    }
    else if(oneCount!=0){
         temp->data=1;
        temp=temp->next;
        oneCount--;
    }
    else if(twoCount!=0){
         temp->data=2;
        temp=temp->next;
        twoCount--;
    }
   }
}

//without replacing

void sorty(Node* &head){
    Node* zeroHead=new Node(-1);
    Node* zeroTail=zeroHead;
     Node* oneHead=new Node(-1);
    Node* oneTail=oneHead;
     Node* twoHead=new Node(-1);
    Node* twoTail=twoHead;
    Node* curr=head;

    // creating seperate list of 0s 1s and 2s
    while(curr!=NULL){
        if(curr->data==0) insertAtTail(zeroTail,curr);
        if(curr->data==1) insertAtTail(oneTail,curr);
        if(curr->data==2) insertAtTail(twoTail,curr);
        curr=curr->next;
    }

    //merging the 3 list
     if(oneHead->next==NULL) {
        zeroTail->next=twoHead->next;
     }else{
        zeroTail->next=oneHead->next;
     }
     oneTail->next=twoHead->next;
     twoTail->next=NULL;
     head=zeroHead->next;
   oneHead->next=NULL;
   twoHead->next=NULL;
   zeroHead->next=NULL;
}

int main(){
Node* node1=new Node(0);
  Node* head=node1;
insertAtHead(head,2);
insertAtHead(head,2);
print(head);
sorty(head);
print(head);
    return 0;
}