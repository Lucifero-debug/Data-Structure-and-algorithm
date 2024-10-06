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

int getLen(Node* &head){
int cnt=0;
while(head!=NULL){
    head=head->next;
    cnt++;
}
return cnt;
}

int main(){

    Node* node1=new Node(10);
      Node* head=node1;
      insertAtHead(head,24);
      insertAtHead(head,98);
      insertAtHead(head,56);
      insertAtHead(head,61);
      insertAtHead(head,27);
      int res=getLen(head);
      int middle=res/2+1;
      cout<<middle<<endl;
    return 0;
}