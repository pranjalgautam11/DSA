#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    int x,n;
    cout << "Enter number, x and power, n: ";
    cin >> x >> n;
    int m=n,y=x;
    int ans=1;
    while(n>0){
        if(n%2==1){
            ans*=x;
            n-=1;
        }
        else{
            n/=2;
            x*=x;
        }
    }
    cout << "\n" << y << " to the power " << m << " is: " << ans;
}