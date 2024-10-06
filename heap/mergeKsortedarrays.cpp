#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class node{
    public:
    int data;
    int i;
    int j;

    node(int data,int row, int col){
  this->data=data;
  this->i=row;
  this->j=col;
    }
};

class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<node*,vector<node*>,compare>min;

//step 1:-saare arrays k first element insert h
    for(int i=0;i<k;i++){
        node* temp=new node(kArrays[i][0],i,0);
        min.push(temp);
    }

    vector<int>ans;
    //step 2
    while(!min.empty()){
        node* temp=min.top();
        ans.push_back(temp->data);
        min.pop();
        int i=temp->i;
        int j=temp->j;
        if(j+1<kArrays[i].size()){
         node* next= new node(kArrays[i][j+1],i,j+1);
         min.push(next);
        }
    }
    return ans;
}
