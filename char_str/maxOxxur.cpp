#include <iostream>
#include <string>
using namespace std;

char maxi(string s){
    int arr[26]={0};
    for(int i=0;i<s.length();i++){
      if(s[i]>='A' && s[i]<='Z'){
        arr[s[i]-'A']++;
      }
      else if (s[i]>='a' && s[i]<='z')
      {
        arr[s[i]-'a']++;
      }
      
    }
    int ans=0;
    int max=0;
    for (int i = 0; i < 26; i++){
     if(arr[i]>max){
        ans=i;
     } 
    }
    cout<<ans<<endl;
    return ans+'a';
}

int main(){
    string s;
    cin>>s;
    cout<<maxi(s)<<endl;
}