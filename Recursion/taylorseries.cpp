#include <iostream>

using namespace std;

double series(int x, int n){
    static double p=1, f=1;
    double r;

    if(n==0)
        return 1;

    r = series(x,n-1);
    p = p*x;
    f = f*n;
    return r + p/f;
}

int main(){
    cout << series(1,10);
}