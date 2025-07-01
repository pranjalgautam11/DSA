#include <iostream>
using namespace std;

int main(){
    int a,b;
    cout << "Enter a and b: ";
    cin >> a >> b;
    cout << "BEFORE SWAP...\na= " << a << " and b= " << b << endl; 
    a=a^b;
    b=a^b;
    a=a^b;
    cout << "\nAFTER SWAP...\na= " << a << " and b= " << b << endl;
}