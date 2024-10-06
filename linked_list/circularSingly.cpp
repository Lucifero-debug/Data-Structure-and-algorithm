#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=this;
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

void print(Node* tail){
    if(tail==NULL){
        cout<<"List Empty"<<endl;
        return;
    }
    Node* temp=tail;
do
{
    cout<<temp->data<<" ";
    temp=temp->next;
} while (temp!=tail);
cout<<endl;
};

void deleteNode(Node* &tail,int value){
if(tail==NULL){
    cout<<"list empty"<<endl;
    return;
}
Node* temp=tail;
Node* prev=NULL;
while(temp->data!=value){
    prev=temp;
    temp=temp->next;
}
prev->next=temp->next;
temp->next=NULL;
delete temp;
};

void insertAt(Node* &tail,int value,int data){
if(tail==NULL){
    Node* temp=new Node(data);
    temp->next=temp;
    tail=temp;
    return;
}
Node* curr=tail;
while(curr->data!=value){
    curr=curr->next;
}
Node* temp=new Node(data);
temp->next=curr->next;
curr->next=temp;
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

int main(){
    Node* node1=new Node(5);
    Node* tail=node1;

    // print(tail);
    insertAt(tail,5,9);
    // print(tail);
    insertAt(tail,9,14);
    // print(tail);
    insertAt(tail,14,54);
    cout<<isCircular(tail)<<endl;
    // print(tail);
    // deleteNode(tail,14);
    // print(tail);
    return 0;
}