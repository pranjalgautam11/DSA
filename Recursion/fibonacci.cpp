#include <iostream>
using namespace std;

int fibonacciloop(int n){
    int s=0,t0=0,t1=1;
    if(n<=1) return n;
    for(int i=2;i<=n;i++){
        s=t0+t1;
        t0=t1;
        t1=s;
    }
    return s;
}

int fibonaccirecursion(int n){
    if(n<=1) return n;
    else return fibonaccirecursion(n-1)+fibonaccirecursion(n-2);
}

int F[20];
int fibonacciMemoization(int n){
    
    if(n<=1){
        F[n] = n;
        return n;
    }
    else{
        if(F[n-2]==-1) F[n-2] = fibonacciMemoization(n-2);
        if(F[n-1]==-1) F[n-1] = fibonacciMemoization(n-1);
        F[n] = F[n-1]+F[n-2];
        return F[n];
    }
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    int f1 = fibonacciloop(n);
    cout << f1 << endl;
    int f2 = fibonaccirecursion(n);
    cout << f2 << endl;
    for(int i=0;i<20;i++)
        F[i] = -1;
    int f3 = fibonacciMemoization(n);
    cout << f3;
}