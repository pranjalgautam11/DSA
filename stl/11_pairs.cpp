#include <bits/stdc++.h>
using namespace std;

int main(){
    pair <int,int> p1 = {1,5};
    cout << "Pair1 elements: ";
    cout << p1.first << " " << p1.second << endl;

    pair <int, pair <int,int>> p2 = {2,{3,7}};
    cout << "Pair2 elements: ";
    cout << p2.first << " " << p2.second.first << " " << p2.second.second << endl;

    pair <int,int> arr[] = {{5,9},{9,3},{2,0}};
    cout << "Array elements:\n";
    for(int i=0;i<3;i++) cout << arr[i].first << " " << arr[i].second << endl;
}