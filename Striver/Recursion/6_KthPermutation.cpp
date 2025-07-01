#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int fac = 1;
        vector<int> number;
        for(int i=1; i<n; i++){
            fac = fac * i;
            number.push_back(i);
        }
        number.push_back(n);
        string str = "";
        k = k - 1; // Convert k to 0th index
        while(true){
            str += to_string(number[k/fac]);
            number.erase(number.begin()+k / fac);
            if(number.size() == 0)
                break;
            k = k % fac;
            fac = fac/number.size();
        }
        return str;
    }
};

int main(){
    int n = 5;
    int k = 2;
    Solution obj;
    string ans = obj.getPermutation(n,k);
    cout << ans;
}