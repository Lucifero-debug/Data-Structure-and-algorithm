#include <iostream>
using namespace std;
#include <vector>

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

//chutiya bnane wla tareeka array m daalke compare krlo
bool palin(Node* head){
vector <int> v;
Node* temp=head;
while(temp!=NULL){
v.push_back(temp->data);
temp=temp->next;
}
int s=0;
int e=v.size()-1;
while(s<=e){
    if(v[s]!=v[e]) return false;
    s++;
    e--;
}
return true;
}
Node* getMid(Node* head){
    if(head==NULL) return head;
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=NULL && fast!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow; 
}
Node* reverse(Node* &head){
    Node* curr=head;
    Node* prev=NULL;
    Node* next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    return head;
}

// jyada optimised tareeka mid nikalo,mid ke baad se revrse krdo list fir compare krlo
bool palin1(Node* head){
Node* mid=getMid(head);
Node* next=mid->next;
mid->next=reverse(next);
Node* s=head;
Node* com=mid->next;
while(com!=NULL){
    if(s->data!=com->data) return false;
    s=s->next;
    com=com->next;
}
return true;
}

int main(){
    Node* node1=new Node(1);
    Node* head=node1;
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
print(head);
cout<<palin1(head)<<endl;
    return 0;
}