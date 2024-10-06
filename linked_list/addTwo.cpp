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

Node* add(Node* head1,Node* head2){
Node* first=reverse(head1);
Node* second=reverse(head2);
Node* res=new Node(-1);
Node* ans=res;
int digit=0;
int carry=0;
while(first!=NULL || second!=NULL || carry!=0){
    
      int val1 = (first != NULL) ? first->data : 0;
        int val2 = (second != NULL) ? second->data : 0;
        int temp = val1 + val2 + carry;
    carry=temp/10;
    digit=temp%10;
       ans->next = new Node(digit);
    ans=ans->next;
     
        if(first != NULL) first = first->next;
        if(second != NULL) second = second->next;
}
    res = reverse(res->next); 
return res;
}

//algo revrese both numbers and start adding from left

int main(){
  Node* node1=new Node(1);
   Node* head1=node1;
    insertAtHead(head1,2);
    insertAtHead(head1,3);
  Node* node2=new Node(4);
   Node* head2=node2;
    insertAtHead(head2,5);
    print(head1);
    print(head2);
   Node* ans= add(head1,head2);
print(ans);
    return 0;
}