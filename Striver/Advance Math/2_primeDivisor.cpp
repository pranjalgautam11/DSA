#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    vector<int> v;
    int n;
    cout << "Enter n: ";
    cin >> n;
    for(int i=2;i<sqrt(n);i++){
        if(n%i==0){
            v.push_back(i);
            while(n%i==0) n/=i;
        }
    }
    if(n!=1) v.push_back(n);
    cout << "\nPrime divisors: ";
    for(int i=0;i<v.size();i++) cout << v[i] << " ";
}