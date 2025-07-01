#include <iostream>
using namespace std;

int main(){
    int num;
    cout << "Enter number: ";
    cin >> num;
    if((num&(num-1))==0)
        cout << "Is power of 2" << endl;
    else    
        cout << "Is not power of 2" << endl;
}