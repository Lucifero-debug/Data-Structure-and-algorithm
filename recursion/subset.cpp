#include <iostream>
using namespace std;
#include <vector>

void subset(string str,vector<string>& ans,int index,string temp){
    if(index>=str.size()){
        ans.push_back(temp);
        return;
    }
    //include
    subset(str,ans,index+1,temp+str[index]);
    //exclude
    subset(str,ans,index+1,temp);
}

int main(){
    string str;
    cout<<"enter string"<<endl;
   cin>>str;
vector<string>ans;
subset(str,ans,0,"");
for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<endl;
}
    return 0;
}