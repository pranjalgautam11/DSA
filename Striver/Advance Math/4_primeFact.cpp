#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> spf(n + 1);  // smallest prime factor array 
    for (int i = 2; i <= n; ++i) spf[i] = i; 
    for (int i = 2; i * i <= n; ++i) {
        if (spf[i] == i) { 
            for (int j = i * i; j <= n; j += i) {
                if (spf[j] == j) spf[j] = i; 
            }
        }
    }
    vector<int> factors;
    while (n != 1) {
        factors.push_back(spf[n]);
        n /= spf[n];
    }
    cout << "Prime factors are: ";
    for (int factor : factors) cout << factor << " ";
}
