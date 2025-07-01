#include <iostream>
using namespace std;

int XOR(int n){
    if(n%4==0) return n;
    else if(n%4==1) return 1;
    else if(n%4==2) return n+1;
    else return 0;
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "XOR of numbers until n: " << XOR(n);

    // XOR in range 
    int l,r;
    cout << "\n\nEnter range l and r: ";
    cin >> l >> r;
    cout << "XOR of numbers between l and r: ";
    int x=XOR(l-1);
    int y=XOR(r);
    cout << (x^y);
}