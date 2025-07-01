#include <bits/stdc++.h>
using namespace std;

void print(unordered_map<int, string> um){
    for (auto i : um)
        cout << i.first << " " << i.second << endl;
}
int main() {
    
    // Create an empty unordered_map
    unordered_map<int, string> um1;
    
    // Creating an unordered_map using
    // initializer list
    unordered_map<int, string> um2 = {{1, "Geeks"}, {2, "For"}, {3, "C++"}};
    
    print(um1);
    cout << endl;
    print(um2);

    // ----------INSERTION-----------
    unordered_map<int, string> um;
    
    // Insert elements using square brackets
    um[1] = "Geeks";
    
    // Insert elements using insert() method
    um.insert({2, "For"});
    um.insert({3, "C++"});

    for (auto i : um) 
        cout << i.first << ": " << i.second << endl;

    // --------- FINDING ---------
    
    unordered_map<int, string> um = {{1, "Geeks"}, {2, "For"}, {3, "C++"}};
    
    // Finding element with key 2
    auto it = um.find(2);
    
    if (it != um.end())
        cout << it->first << ": " << it->second;
    else cout << "Not Found";

    // ----------DELETION----------

    unordered_map<int, string> um = {{1, "Geeks"}, {2, "For"}, {3, "C++"}};
    
    // Delete element which have key 2
    um.erase(2);
    
    // Delete first element
    um.erase(um.begin());
  
    for(auto it = um.begin(); it != um.end(); it++)
        cout << it->first << ": " << it->second << endl;

    return 0;
}
