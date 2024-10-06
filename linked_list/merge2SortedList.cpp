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

void solve(Node* &first,Node* &second){
    
    Node* curr1=first;
    Node* next1=curr1->next;
    Node* curr2=second;
    Node* next2=curr2->next;
    if(next1==NULL){
        first->next=second;
        return;
    } else{
        while(next1!=NULL && curr2!=NULL){
            if(curr2->data>=curr1->data && curr2->data<=next1->data){

                //ADDING LIST BETWWEN
                curr1->next=curr2;
                next2=curr2->next;
                curr2->next=next1;

                //UPDATING POINTERS
                curr1=curr2;
                curr2=next2;
            }
            else{
                curr1=next1;
                next1=next1->next;
            }
        }
        if(next1==NULL){
            curr1->next=curr2;
        }
    }
}

int main(){
Node* node1=new Node(5);
Node* first=node1;
// insertAtHead(first,3);
// insertAtHead(first,1);
Node* node2=new Node(10);
Node* second=node2;
insertAtHead(second,6);
insertAtHead(second,3);
insertAtHead(second,1);
print(first);
if(first->data <= second->data) solve(first,second);
else solve(second,first);
print(first);
  delete first;
    return 0;
}