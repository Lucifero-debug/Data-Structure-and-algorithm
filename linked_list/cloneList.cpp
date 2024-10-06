#include <iostream>
using namespace std;

class Node {

    public:
    int data;
    Node* next;
    Node* random;

    Node(int data){
        this->data=data;
        this->next=NULL;
        this->random=NULL;
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

  void insertAtTail(Node* &head,Node* &tail,int data){
            Node* newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }else{
            tail->next=newNode;
            tail=tail->next;
        }
    }

Node* copyRandomList(Node* head) {
        // step 1:-create a clone list
        Node* temp=head;
        Node* clonehead=NULL;
        Node* clonetail=NULL;
        while(temp!=NULL){
            insertAtTail(clonehead,clonetail,temp->data);
            temp=temp->next;
        }
        //step 2:- add clone in between original list
        Node* original=head;
        Node* clone=clonehead;
        while(original!=NULL && clone!=NULL){
       Node* next=original->next;
       original->next=clone;
       original=next;
       next=clone->next;
       clone->next=original;
       clone=next;
        }
        //step 3:- random pointer copying
        temp=head;
        while(temp!=NULL){
            if(temp->next!=NULL){
                temp->next->random=temp->random?temp->random->next:temp->random;
            //     if(temp->random!=NULL){
            // temp->next->random=temp->random->next;
            //     }else{
            //         temp->next=temp->random;
            //     }
            }
            temp=temp->next->next;
        }

        //step 4:-revert changes done in step 2
        original=head;
    clone=clonehead;
        while(original!=NULL && clonehead!=NULL){
          original->next=clone->next;
             original=original->next;
            if(original!=NULL){
                    clone->next=original->next;
            }
            clone=clone->next;
        }
        //step 5:- return ans that is clonehead
        return clonehead;
    }

    void print(Node* &head){
    Node *temp=head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){

   Node* start = new Node(1);
    start->next = new Node(2);
    start->next->next = new Node(3);
    start->next->next->next = new Node(4);
    start->next->next->next->next = new Node(5);
 
    // 1's random points to 3
    start->random = start->next->next;
 
    // 2's random points to 1
    start->next->random = start;
 
    // 3's and 4's random points to 5
    start->next->next->random =
                    start->next->next->next->next;
    start->next->next->next->random =
                    start->next->next->next->next;
 
    // 5's random points to 2
    start->next->next->next->next->random =
                                      start->next;
 
    cout << "Original list : \n";
    print(start);
 
    cout << "\nCloned list : \n";
    Node *cloned_list = copyRandomList(start);
    print(cloned_list);

    return 0;
}