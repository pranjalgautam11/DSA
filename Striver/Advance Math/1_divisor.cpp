#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    int n;
    cout << "Enter n: ";
    cin >> n;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            v.push_back(i);
            if(n/i!=i) v.push_back(n/i); // will not give sorted list
        }
    }
    cout << "\nDivisors: ";
    for(int i=0;i<v.size();i++) cout << v[i] << " ";
}