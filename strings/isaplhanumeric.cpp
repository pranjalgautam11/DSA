#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int isalphanum(string str){
    for(int i=0; i<str.length(); i++){
        if(!isalpha(str[i]) && !isdigit(str[i]))
            return 0;
    }
    return 1;
}

int main(){
    string name = "howareyou";
    if(isalphanum(name))
        cout << "Valid string";
    else
        cout <<"Invalid String";
}