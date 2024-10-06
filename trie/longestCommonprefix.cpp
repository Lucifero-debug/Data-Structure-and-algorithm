#include <iostream>
using namespace std;
#include <vector>

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        childCount=0;
        isTerminal=false;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(char ch){
        root=new TrieNode(ch);
    }

void insertUtil(TrieNode* root,string word){
//base case recursion
if(word.length()==0){
root->isTerminal=true;
return;
}
int index=word[0]-'a';
TrieNode* child;

//present
if(root->children[index]!=NULL){
child=root->children[index];
}else{
    //absent
child=new TrieNode(word[0]);
root->children[index]=child;
root->childCount++;
}
//recursion
insertUtil(child,word.substr(1));
}

void insertWord(string word) { return insertUtil(root, word); }
void lcp(string str,string&ans){
for(int i=0;i<str.length();i++){
char ch=str[i];
if(root->childCount==1 && !root->isTerminal){
    ans.push_back(ch);
    //aage bdh jaao
    int index=ch-'a';
    root=root->children[index];
}else{
    break;
}
if(root->isTerminal){
    break;
}
}
}
};


string longestCommonPrefix(vector<string> &arr, int n) {
// Write your code here
Trie *t=new Trie('\0');
//insert krdo string into trie
for(int i=0;i<n;i++){
    t->insertWord(arr[i]);
}
string first=arr[0];
string ans="";
t->lcp(first,ans);
return ans;
}

int main(){
    return 0;
}