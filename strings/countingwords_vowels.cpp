#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main(){
    string name = "how are you";
    int consonant=0, vowel=0, word=1;
    transform(name.begin(), name.end(),name.begin(), ::tolower);
    for(int i=0; i < name.length(); i++){
        char c = name[i];
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            vowel++;
        else if(c>=97 && c<=122)
            consonant++;
        if(name[i] == ' ' && name[i-1] != ' ')
            word++;
    }
    cout << "vowel: " << vowel << endl;
    cout << "consonant: " << consonant <<endl;
    cout << "words: " << word;
}