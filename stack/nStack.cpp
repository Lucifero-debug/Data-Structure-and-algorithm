#include <iostream>
using namespace std;

class NStack
{
int *arr;
int *top;
int *next;
int freespot;

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        arr=new int[S];
        next=new int[S];
        top=new int[N];
        for(int i=0;i<N;i++){
            top[i]=-1;
        }
        for(int i=0;i<S;i++){
            next[i]=i+1;
        }
        next[S-1]=-1;
        freespot=0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        //find index
        int index=freespot;
        //freespot update
        freespot=next[index];
        //insert in array
        arr[index]=x;
        //update next
        next[index]=top[m-1];
        //update top
        top[m-1]=index;
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        //check for empty
     if(top[m-1]==-1) return -1;
    //find index to pop
      int index=top[m-1];
      //update top
       top[m-1]=next[index];
       //update next
       next[index]=freespot;
       //update freespot
       freespot=index; 
       return arr[index];
    }
};

int main(){
    return 0;
}