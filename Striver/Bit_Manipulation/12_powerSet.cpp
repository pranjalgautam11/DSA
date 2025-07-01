#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> a[i];
    int subsets = 1 << n;
    vector<vector<int>> v;
    for (int i = 0; i < subsets; i++) {
        vector<int> l;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) l.push_back(a[j]);
        }
        v.push_back(l);
    }
    cout << "Power set:";
    for (const auto& subset : v) {
        for (int elem : subset) cout << elem << " ";
        cout << endl;
    }
}
