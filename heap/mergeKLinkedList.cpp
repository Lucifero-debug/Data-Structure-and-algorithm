#include <iostream>
using namespace std;
#include <queue>


class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

class compare {
    public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data; // Min-heap (smallest element on top)
    }
};

Node* mergeKLists(vector<Node*> &listArray){
    // Write your code here.
   priority_queue<Node*,vector<Node*>,compare>min;
   int k=listArray.size();
   if(k==0) return NULL;
   //step 1:-insert first element of every array
   for(int i=0;i<k;i++){
       if(listArray[i]!=NULL){
       min.push(listArray[i]);
       }
   }
   Node* head=NULL;
   Node* tail=NULL;
while(!min.empty()){
    Node* top=min.top();
    min.pop();
    if(top->next!=NULL){
        min.push(top->next);
    }
    if(head==NULL){
        head=top;
        tail=top;
    }else{
        tail->next=top;
        tail=top;
    }
}
return head;
}


int main(){
    return 0;
}