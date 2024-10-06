#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

int maximumFrequency(vector<int> &arr, int n)
{
    //Write your code here
    unordered_map<int,int>count;
    int maxFreq=-1;
    int maxAns=-1;

    for(int i=0;i<arr.size();i++){
        count[arr[i]]++;
        maxFreq=max(maxFreq,count[arr[i]]);
    }
    for(int i=0;i<arr.size();i++){
        if(maxFreq==count[arr[i]]){
            maxAns=arr[i];
            break;
        }
    }
    return maxAns;
}

int main(){
    return 0;
}