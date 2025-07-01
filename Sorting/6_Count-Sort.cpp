#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> count(vector<int> &v) {
    int max = *max_element(v.begin(), v.end());
    vector<int> temp(max+1, 0);
    for (int i = 0; i < v.size(); i++) {
        temp[v[i]]++;
    }
    return temp;
}

void CountSort(vector<int>& v) {
    vector<int> c = count(v);
    vector<int> temp(v.size());
    int index = 0;
    
    for (int i = 0; i < c.size(); i++) {
        while (c[i] > 0) {
            temp[index++] = i;
            c[i]--;
        }
    }
    
    v.swap(temp);
}

void display(const vector<int>& v) {
    for (int e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v = {10,4,2,19,6,12,2,9,6};

    cout << "COUNTING SORT...\n";
    CountSort(v);
    display(v);
}
