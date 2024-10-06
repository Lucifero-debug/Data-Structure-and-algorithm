#include <iostream>
using namespace std;
#include <stack>
#include <string>

int findMinimum(string s){
//for odd length

if(s.length()%2!=0){
    return -1;
}
stack<char> st;

//removing valid
for(int i=0;i<s.length();i++){
    char ch=s[i];

    if(ch=='('){
        st.push(ch);
    }
    else{
// ch is closed bracket
     if(!st.empty()&&st.top()=='('){
st.pop();
     }
else{
    st.push(ch);
}
    }

}
    //stack contains invalid expression now
    int a=0,b=0; //a count for closed and b count for open bracket
    while(!st.empty()){
        if(st.top()=='(') b++;
        else a++;
        st.pop();
    }
int ans= (a+1)/2 + (b+1)/2;
return ans;
}

int main(){
string str="((()";
cout<<findMinimum(str)<<endl;

    return 0;
}