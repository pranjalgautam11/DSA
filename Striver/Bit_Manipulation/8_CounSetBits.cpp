#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter number: ";
    cin >> n;
    int set=1;
    while(n>1){ 
        set += n&1;  // odd check
        n=n>>1;  // n/=2
    }
    cout << "Set bits = " << set;

    // method 2
    int num;
    cout << "\n\nEnter number: ";
    cin >> num;
    int bits=0;
    while(num!=0){ 
        num=num&(num-1);  //clearing last set bit
        bits++;
    }
    cout << "Set bits = " << bits;
}