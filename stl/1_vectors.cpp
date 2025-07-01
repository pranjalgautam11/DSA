// Vector: Dynamic sized array which can be resized automatically. 

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <int> v1; 
    v1.push_back(1);
    v1.emplace_back(2); // faster than pushback

    vector <pair<int,int>> v2;
    v2.push_back({1,2});
    v2.emplace_back(1,2);

    // ------------ INITIALIZATION METHODS -----------------
    vector <int> v3 (5,100); // 100,100,100,100,100 (size,value)
    vector <int> v4 (5); // 0,0,0,0,0
    vector <int> v5 (5,20); // 20,20,20,20,20
    vector <int> v6(v5); // 20,20,20,20,20

    int m = 2, n=3;
    vector<vector<int>> matrix(m, vector<int>(n, 0)); // Initiaizing 2D vector

    // ---------------- ITERATOR -------------------
    vector <int> v7 {20,40,60,80,100};
    vector <int>::iterator it1 = v7.begin();
    it1++;
    cout << *(it1) << " "; // 40 
    it1+=3;
    cout << *(it1) << " " << endl; // 100 

    vector <int>::iterator it2 = v7.end(); // after 100
    vector <int>::reverse_iterator it3 = v7.rend(); // before 20
    vector <int>::reverse_iterator it4 = v7.rbegin(); // 100

    cout << v7.at(2) << " "; // 60 
    cout << v7.front() << " "; // 20 
    cout << v7.back() << " "; // 100
    cout << endl << endl;

    for(vector <int>::iterator it=v7.begin(); it!=v7.end(); it++)
        cout << *(it) << " ";
    cout << endl;
    for(auto it=v7.begin(); it!=v7.end(); it++) // auto assign data type
        cout << *(it) << " ";
    cout << endl;
    for(auto it : v7) // for each loop
        cout << it << " ";
    cout << endl << endl;

    // ----------------- ERASE ------------------
    // 20 40 60 80 100
    v7.erase(v7.begin()+1); // 20 60 80 100 (erase at 2nd position)
    v7.erase(v7.begin()+1,v7.begin()+3); // 20 100 [1-3}

    // ---------------- INSERT ------------------
    vector <int> v8 (2,100); // 100,100
    v8.insert(v8.begin(),200); // 200,100,100
    v8.insert(v8.begin()+1,2,300); // 200.300,300,100,100

    vector <int> c(2,50);
    v8.insert(v8.begin()+1,c.begin(),c.end()); // 200,50,50,300,300,100,100

    cout << v8.size(); // 7
    cout << endl ;

    v8.pop_back(); // 200,50,50,300,300,100

    vector <int> v9 {40,70,30,60};
    v8.swap(v9); // v8-> 40,70,30,60    v9-> 200,50,50,300,300,100

    v9.clear(); // empty vector 

    cout << v9.empty(); // true 
}