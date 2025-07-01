#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void duplicate(string str){
    int hash[26] = {0};
    for(int i=0; i<str.length(); i++)
        hash[str[i]-97]++;
    
    for(int i=0; i<26; i++){
        if(hash[i]>1)
            cout << (char)(i+97) << " appears " << hash[i] << " times" <<endl;
    }
}

void bitwiseduplicate(string str){
    long int h=0, x=0;
    for(int i=0; i<str.length(); i++){
        x = 1;
        x = x << (str[i]-97);
        if((x&h)>0)
            cout << str[i] << " is a duplicate" << endl;
        else
            h = x | h;
    }
}

int main(){
    string name = "kartikgautam";
    duplicate(name);
    bitwiseduplicate(name);
}