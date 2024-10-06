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
Node* temp=new Node(d);
    if(head==NULL){
head=temp;
    }else{
    temp->next=head;
    head=temp;
    }
}

void print(Node* &head){
    Node *temp=head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

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

Node* getIntersect(Node* &head){
if(head==NULL) return 0;
Node* fast=head;
Node* slow=head;
while(slow!=NULL && fast!=NULL){
    fast=fast->next;
    if(fast!=NULL){
        fast=fast->next;
    }
    slow=slow->next;
    if(slow==fast){
     return slow;
    };
}
return 0;
}

Node* getStart(Node* &head){
    if(head==NULL) return 0;
Node* intersect=getIntersect(head);
Node* slow=head;
while(intersect!=NULL && slow!=NULL){
    intersect=intersect->next;
slow=slow->next;
if(slow==intersect){
return slow;
}
}
}

void removeLoop(Node* &head){
    if(head==NULL) return;
    Node* start=getStart(head);
    Node* temp=start;
    while(temp->next!=start){
        temp=temp->next;
    }
    temp->next=NULL;
}


int main(){

    Node* node1=new Node(10);
      Node* head=node1;
      insertAtHead(head,24);
      insertAtHead(head,98);
      insertAtHead(head,56);
      insertAtHead(head,61);
      insertAtHead(head,27);
      print(head);
       head->next->next->next->next->next = head->next->next->next->next;
       cout<<"before"<<(head->next->next->next->next->next)->data<<endl;
       removeLoop(head);
       cout<<"need"<<(head->next->next->next->next->next)->data<<endl;

    //   if(isLoop(head)){
    //     cout<<"Loop found"<<endl;
    //   }
    //   else{
    //     cout<<"Loop not found"<<endl;
    //   }
    return 0;
}