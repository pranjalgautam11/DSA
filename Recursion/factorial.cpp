#include <iostream>

using namespace std;

int factorial(int n){
    if(n>0){
        return factorial(n-1) * n;
    }
    return 1;
}

int main(){
    int num;
    cout << "Enter the number ";
    cin >> num;
    cout << "Factorial of " << num << " is " << factorial(num);
}