/* 
    Unordered Set: STL Unordered Set stores the unique keys in the form of hash table. 
    The order is randomized but insertion, deletion and search are fast.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    // declaring set for storing string data-type
    unordered_set<string> stringSet;

    // ------------ INSERTION --------------

    stringSet.insert("code");
    stringSet.insert("in");
    stringSet.insert("c++");
    stringSet.insert("is");
    stringSet.insert("fast");

    string key = "slow";

    // ------------ SEARCH -----------------

    if (stringSet.find(key) == stringSet.end())
        cout << key << " not found" << endl << endl;
    else
        cout << "Found " << key << endl << endl;

    key = "c++";
    if (stringSet.find(key) == stringSet.end())
        cout << key << " not found\n";
    else
        cout << "Found " << key << endl;

    // now iterating over whole set and printing its
    // content
    cout << "\nAll elements : ";
    unordered_set<string>::iterator itr;
    for (itr = stringSet.begin(); itr != stringSet.end(); itr++)
        cout << (*itr) << endl;
}

