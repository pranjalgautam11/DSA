#include <bits/stdc++.h>
#include <vector>
using namespace std;

int noOfSubstringsWith3Char(vector<int> v){
    int count=0;
    int lastSeen[3]={-1,-1,-1};
    for(int i=0;i<v.size();i++){
        lastSeen[v[i]-'a']=i; // last index
        if(lastSeen[0]!=-1 && lastSeen[1]!=-1 && lastSeen[2]!=-1) 
            count+=(1+min(lastSeen[0],min(lastSeen[1],lastSeen[2])));
    }
    return count;
}

int main(){
    vector<int> v;
    int n;
    char e;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter elements: ";
    for(int i=0;i<n;i++){
        cin >> e;
        v.push_back(e);
    }
    cout << "NO OF SUBSTRINGS WITH THREE CHARACTERS: " << noOfSubstringsWith3Char(v);
}