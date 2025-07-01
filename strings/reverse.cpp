#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main(){
    string name = "howareyou";
    cout << name << endl;
    reverse(name.begin(), name.end());
    cout << name;
}