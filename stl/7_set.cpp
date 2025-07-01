// Sets: Unique and Sorted

#include <bits/stdc++.h>
using namespace std;

int main(){
    set<int> s; 
    // --------------- INSERT ------------------
    s.insert(1);
    s.emplace(2);
    s.insert(2);
    s.insert(4);
    s.insert(3);
    s.insert(7);
    for(int e: s) cout << e << " "; 

    // ----------------- FIND ---------------------
    auto it = s.find(3); // ptr to element
    auto itr = s.find(9); // if element not in set then ptr to s.end

    // ------------------- ERASE -------------------
    s.erase(2);

    auto i = s.find(2);
    s.erase(i);

    auto ir = s.find(1);
    auto ie = s.find(4);
    s.erase(ir,ie); // erases from ir to ie-1
    
    // ----------------- COUNT -----------------
    int c = s.count(4); // 0 if not present 1 if present 
}