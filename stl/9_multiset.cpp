#include <bits/stdc++.h>
using namespace std;

int main(){
    multiset<int> ms; // sorted but not unique 
    // --------------- INSERT ------------------
    ms.insert(1);
    ms.emplace(1);
    ms.insert(1); // stores same elements too -> not unique

    //  ------------------- ERASE -------------------
    ms.erase(1); // all occurences erased 
    for(int e: ms) cout << e << " "; 

    ms.erase(ms.find(1)); // erases only first occurence
}