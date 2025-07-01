#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;  
    for (int i = 2; i * i <= n; ++i) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i)prime[j] = false;
        }
    }
    cout << "\nPrime numbers up to " << n << ": ";
    for (int i = 2; i <= n; ++i) {
        if (prime[i]) cout << i << " ";
    }
}
