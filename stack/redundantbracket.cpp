#include <iostream>
using namespace std;
#include <stack>
#include <string>



    

bool brackets(string str){
stack<char> st;
int i=0;
while(str[i]!='\0'){
    char ch=str[i];
    if(ch=='('  || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
        st.push(ch);
    }
    else{
    if(ch==')' ){
        bool isRedundant=true;
     while(!st.empty()&&st.top()!='('){
        char top=st.top();
        if(top=='+' || top=='-' || top=='*' || top=='/'){
 isRedundant=false;
        }
        st.pop();
     }
     if(isRedundant) return true;
     st.pop();
    }
    } 
    i++;
}
return false;
}

int main(){
string str="(a+b)";
cout<<brackets(str)<<endl;;

    return 0;
}