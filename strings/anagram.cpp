#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int anagram(string s1, string s2){
    int hash[26] = {0};
    if(s1.length()!=s2.length())
        return 0;
    for(int i=0; i<s1.length(); i++){
        hash[s1[i]-97]++;
        hash[s2[i]-97]--;
    }
    for(int i=0; i<26; i++){
        if(hash[i]!=0)
            return 0;
    }
    return 1;
}

int main(){
    string s1 = "pgequalsbj";
    string s2 = "bjequalspg";
    if(anagram(s1,s2))
        cout << "Is a anagram" <<endl;
    else
        cout << "Not a anagram";
}