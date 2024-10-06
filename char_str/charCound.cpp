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
string count(string s){
    int arr[26]={0};
    for(int i=0;i<s.length();i++){
        arr[lower(s[i])-'a']++;
    }
    string temp;
    for(int i=0;i<26;i++){
        if(arr[i]!=0 && arr[i]!=1){
            temp.push_back(i+'a');
            temp.append(to_string(arr[i]));
        }
        else if(arr[i]==1){
            temp.push_back(i+'a');
        }
        else if(arr[i]>9){
            while(arr[i]>0){
                temp.append(to_string(arr[i]%10));
                arr[i]=arr[i]/10;
            }
        }
    }
    return temp;
}

int main(){
    string s;
    cin>>s;
    string m=count(s);
    cout<<m<<endl;
    return 0;
}
