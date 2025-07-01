#include <iostream>
using namespace std;

int main(){
    int A,B;
    cout << "Enter numbers A and B: ";
    cin >> A >> B;
    int num = A^B;
    int bits=0;

    while(num!=0){
        if(num%2 == 1)
            bits++;
        num = num/2;
    }
    // while(num!=0){ 
    //     num=num&(num-1);  
    //     bits++;
    // }
    cout << "Minimum bits to convert A to B = " << bits;
}