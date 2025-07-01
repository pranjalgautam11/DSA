#include <iostream>
#include <string>
#include <vector>

using namespace std;

void permutation(string s, string res, vector<int> &arr, int k) {
    int n = s.length();
    if (k == n) {
        cout << res << endl;
    } else {
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                res[k] = s[i];
                arr[i] = 1;
                permutation(s, res, arr, k + 1);
                arr[i] = 0;
            }
        }
    }
}

void permutation1(string s, int l, int h){
    if(l==h)
        cout << s <<endl;
    else{
        for(int i=l; i<=h; i++){
            swap(s[l], s[h]);
            permutation1(s,l+1,h);
            swap(s[l],s[i]);
        }
    }
}

int main() {
    string s1 = "abc";
    vector<int> arr(s1.length(), 0);
    string res(s1.length(), ' '); // Initialize res with spaces of length s1
    permutation(s1, res, arr, 0);
    permutation1(s1,0,2);
    return 0;
}
