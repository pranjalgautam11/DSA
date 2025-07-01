#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int ispalindrome(string str){
    int i=0, j=str.length()-1;
    while(i<=j){
        if(str[i] != str[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}

int main(){
    string name = "nitin";
    if(ispalindrome(name))
        cout << "palindrome" << endl;
    else    
        cout << "Not a palindrome";
}