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

class Stack{

public:
Node* node1;
Node* top;
int data;

Stack(){
    node1=new Node(-1);
    top=node1;
    node1->next=NULL;
}

void push(int d){
    //first element
    if(top->data==-1){
    Node* temp=new Node(d);
    node1->next=temp;
    temp->next=NULL;
    top=temp;
    }else{
        Node* temp=new Node(d);
        temp->next=NULL;
        top->next=temp;
        top=temp;
    }
}

int pop(){
    Node* prev=NULL;
    Node* head=node1;
    while(head!=top){
        prev=head;
        head=head->next;
    }
    int ans=head->data;
    // head->data=-1;
    prev->next=NULL;
    top=prev;
    return ans;
}
int front(){
int ans=top->data;
return ans;
}
};

int main(){
Stack st;
st.push(5);
cout<<st.front()<<endl;
st.push(9);
st.push(87);
st.push(34);
st.push(65);
cout<<st.front()<<endl;
st.pop();
cout<<st.front()<<endl;
st.pop();
cout<<st.front()<<endl;

    return 0;
}