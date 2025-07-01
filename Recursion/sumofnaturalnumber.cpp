#include <iostream>

using namespace std;

int sum(int n){
    if(n>0){
        return sum(n-1) + n;
    }
    return 0;
}

int main(){
    int num;
    cout << "Enter the number ";
    cin >> num;
    cout << "Sum of First " << num << " number is " << sum(num);
}