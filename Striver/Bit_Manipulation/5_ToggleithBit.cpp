#include <iostream>
using namespace std;

int main(){
    int num,i;
    cout << "Enter number and index: ";
    cin >> num >> i;
    num = num^(1<<i);
    cout << num << endl;
}