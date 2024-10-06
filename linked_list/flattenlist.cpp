#include <iostream>
using namespace std;

class Node {

    public:
    int data;
    Node* next;
    Node* child;

    Node(int data){
        this->data=data;
        this->next=NULL;
        this->child=NULL;
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

Node* merge(Node* a,Node* b){
    if(a==NULL) return b;
    if(b==NULL) return a;
    Node* result=NULL;
    if(a->data<=b->data){
    result=a;
    result->child=merge(a->child,b);
    }else{
        result=b;
        result->child=merge(a,b->child);
    }
    result->next=NULL;
    return result;
}

Node* flattenLinkedList(Node* head) 
{
	 if(head==NULL || head->next==NULL) return head;
     return merge(head,flattenLinkedList(head->next));

}

int main(){
    return 0;
}