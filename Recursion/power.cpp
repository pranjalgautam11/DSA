#include <iostream>

using namespace std;

int power(int num, int pow){
    if(pow==0)
        return 1;

    return power(num,pow-1) * num;
}

int main(){
    int num, pow;
    cout << "Enter the number ";
    cin >> num;
    cout << "Enter the power ";
    cin >> pow;
    cout << num <<"^" << pow << " = " << power(num,pow);
}