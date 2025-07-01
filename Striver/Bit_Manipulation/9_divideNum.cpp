#include <iostream>
using namespace std;

int main(){
    int n,d;
    cout << "Enter dividend and divisor: ";
    cin >> n >> d;
    int r=n;
    int res=0;
    if(n==d) res = 1;
    while(n>=d){
        int c=0; // powers of 2
        while(n>=(d<<(c+1))) c++; // d*2^c+1
        res += 1<<c; // 2^c
        n-=(d<<c); // d*2^c
    }
    cout << "Quotient on dividing " << r << " and " << d << " is " << res;
}