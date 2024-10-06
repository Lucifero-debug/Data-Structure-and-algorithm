#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int d){
        this->data=d;
        this->next=this;
        this->prev=this;
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

void insertAt(Node* tail,int value,int data){
    if(tail==NULL){
        Node* temp=new Node(data);
        tail=temp;
        temp->next=temp;
        temp->prev=temp;
        return;
    }
    Node* curr=tail;
    while(curr->data!=value){
        curr=curr->next;
    }
    Node* temp=new Node(data);
    temp->next=curr->next;
    temp->prev=curr;
    curr->next=temp;
}

void deleteNode(Node* &tail,int value){
    if(tail==NULL){
        cout<<"List Empty"<<endl;
        return;
    }
    Node* temp=tail;
    Node* prev=NULL;
    while(temp->data!=value){
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    temp->next->prev=prev;
    temp->next=NULL;
    temp->prev=NULL;
    delete temp;
}

int main(){
Node* node1=new Node(5);
Node* tail=node1;
print(tail);
insertAt(tail,5,9);
print(tail);
insertAt(tail,9,45);
insertAt(tail,45,17);
insertAt(tail,17,91);
print(tail);
deleteNode(tail,45);
print(tail);
    return 0;
}