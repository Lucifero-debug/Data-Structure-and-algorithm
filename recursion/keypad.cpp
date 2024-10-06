#include <iostream>
#include <vector>
using namespace std;

void solve(string str,vector<string>& ans,string arr[],int index,string combo){
if(index>=str.length()) {
    ans.push_back(combo);
    return;
    }
int number=str[index]-'0';
string value=arr[number];
for(int i=0;i<value.size();i++){
    combo.push_back(value[i]);
    solve(str,ans,arr,index+1,combo);
    combo.pop_back();
}
}

int main(){
    cout<<"enter number"<<endl;
    string str;
    vector<string>ans;
    cin>>str;
    string digit[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(str,ans,digit,0,"");
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<endl;
  }
    return 0;
}