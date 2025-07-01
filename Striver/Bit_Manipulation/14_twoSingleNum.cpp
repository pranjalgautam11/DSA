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
    int right=(x&(x-1))^x; // rightmost set bit
    int b1=0,b2=0; // buckets
    for(int i=0;i<n;i++){
        if(v[i]&right) b1=b1^v[i];
        else b2=b2^v[i];
    }
    cout << "Two numbers that are single: " << b1 << " and " << b2;
}