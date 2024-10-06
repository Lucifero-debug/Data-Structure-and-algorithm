#include <iostream>
using namespace std;
#include <queue>

string FirstNonRepeating(string A){
		    
		    // Code here
		    string ans;
		    queue<char>q;
		    
		    int arr[26]={0};
		   
		    for(int i=0;i<A.size();i++){
		       char ch=A[i];
		       arr[ch-'a']++;
		       if(arr[ch-'a']==1){
		           q.push(ch);
		           ans.push_back(q.front());
		       }else{
		         while(!q.empty()&&arr[q.front()-'a']>1){
		             q.pop();
		         }
		         if(q.empty()){
		             ans.push_back('#');
		         }else{
		             ans.push_back(q.front());
		         }
		       }
		    }
		 return ans;   
		}

int main(){

    return 0;
}