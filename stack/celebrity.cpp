#include <iostream>
using namespace std;
#include <vector>
#include <stack>

bool knows(int a,int b,vector<vector<int> > mat){
     if(mat[a][b]==0){
         return false;
     }
     else{ 
         return true;
     }
 }

int celebrity(vector<vector<int>>& mat){
   stack<int> st;
        int n=mat.size();
        for(int i=0;i<n;i++){
          st.push(i);  
        }
        while(st.size()>1){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
           if(knows(a,b,mat)){ // a b ko jaanta h
               st.push(b);
           }
           else{
               st.push(a);
           }
        }
        //verify
          if (st.empty()) return -1;
        int candidate=st.top();
        int rowCheck=true;
        for(int i=0;i<n;i++){
            if(mat[candidate][i]==1) {
                rowCheck=false;
                break;
            };
        }
        int colCheck=true;
        for(int i=0;i<n;i++){
            if(mat[i][candidate]==0 && i!=candidate) {
                rowCheck=false;
                break;
            }
            
        }
        if(colCheck && rowCheck) return candidate;
        return -1;
}

int main(){
    //rows is for kon janta h column is kisko jaanta h [2][1]=0 meansa 2 1 ko ni jaanta
    // celebrity knows no one and everyone knows celebrity  row all zero and col all one except diagonal

    vector<vector<int>> arr={{0,1,0},{0,0,0},{0,1,0}};
   int ans= celebrity(arr); 
   cout<<ans<<endl;
    return 0;
}