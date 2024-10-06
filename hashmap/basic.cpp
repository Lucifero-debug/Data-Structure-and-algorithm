#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main(){

//creation
map<string,int>m;

//insertion

//1st way
pair<string,int>p=make_pair("shanu",2);
m.insert(p);

//2nd way
pair<string,int>pair2=make_pair("love",3);
m.insert(pair2);

//3rd way
m["mera"]=4;

//search 1st way
cout<<m["mera"]<<endl;
//2nd way
cout<<m.at("shanu")<<endl;

//for entries that are not made
cout<<m["para"]<<endl; //no entry for para so it made a entry with value 0
cout<<m.at("para")<<endl;

//size
cout<<m.size()<<endl;

//to check presence
cout<<m.count("love")<<endl;
cout<<m.count("bro")<<endl;  //count gives 0 for case of absent and 1 for case of present

//erese 
m.erase("love");

//iterator
map<string,int> :: iterator it=m.begin();

while(it !=m.end()){
    cout<<it->first <<" "<<it->second<<endl;
    it++;
}

    return 0;
}