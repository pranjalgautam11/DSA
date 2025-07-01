#include <iostream>
using namespace std;

int main(){
    int num,i;
    cout << "Enter number and index: ";
    cin >> num >> i;
    if((num&(1<<i))!=0)
        cout << "Bit is Set" << endl;
    else    
        cout << "Bit is not Set" << endl;
}