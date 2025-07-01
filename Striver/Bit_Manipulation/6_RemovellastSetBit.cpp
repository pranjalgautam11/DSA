#include <iostream>
using namespace std;

int main(){
    int num,i;
    cout << "Enter number: ";
    cin >> num;
    num = num&(num-1);
    cout << num << endl;
}