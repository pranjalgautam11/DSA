#include <iostream>

using namespace std;

int toh(int n, int A, int B, int C){
    if(n>0){
        toh(n-1,A,C,B);
        cout << A << C <<endl;
        toh(n-1,B,A,C);
    }
}

int fun (int n){ 
    int x=1, k; 
    if (n==1) return x; 
    for (k=1; k<n; ++k) 
    x=x + fun (k) * fun (n - k); 
    return x;
}

int main(){
    cout << fun(5) <<endl;
    cout << toh(3,1,2,3);
}