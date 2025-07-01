// Maps: Key and Value pairs -> unique keys and sorted

#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int,int> m; 
    // --------------- INSERT ------------------
    m[1] = 2;
    m.emplace(3,1);
    m.insert({2,4});

    for(auto e: m) cout << e.first << " " << e.second << endl;
    cout << endl;

    // ------------- ACCESS -------------------
    cout << m[1] << endl;
    cout << m[6] << endl;
    cout << endl;

    // -------------- FIND -----------------
    auto it = m.find(2);
    cout << it->second << endl;
    cout << endl;

    auto itr = m.find(8); // ptr to m.end

    // assigning the elements from m to mp
    map<int, int> mp(m.begin(), m.end());
}