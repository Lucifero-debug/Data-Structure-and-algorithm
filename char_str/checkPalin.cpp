#include <iostream>
#include <string>
using namespace std;

char lower(char ch){
  if(ch<='z' && ch>='a'){
    return ch;
  }
  else{
    ch=ch-'A'+'a';
  }
  return ch; 
}
string remove(string s){
int i=0;
string temp;
for(i=0;i<s.length();i++){
if(s[i]>='A' && s[i]<='Z' || s[i]>='a' && s[i]<='z' || s[i]>='0' && s[i]<='9'){
  temp.push_back(s[i]);
}
}
return temp;
}

bool palin(string s){
string n=remove(s);
cout<<n<<endl;
int i=0,j=n.length()-1;
while(i<=j){
if(lower(n[i]) !=lower(n[j])){
    return 0;
}
else{
    i++;
    j--;
}
}
return 1;
}

int main(){
    string s;
  getline(cin,s);
    cout<<(palin(s)?"TRUE":"FALSE")<<endl;
    return 0;
}