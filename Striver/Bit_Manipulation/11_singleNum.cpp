#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    int n,e;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for(int i=0;i<n;i++){
        cin >> e;
        v.push_back(e);
    }
    int x=0;
    for(int i=0;i<n;i++) x=x^v[i];
    cout << "The single number is: " << x;
}