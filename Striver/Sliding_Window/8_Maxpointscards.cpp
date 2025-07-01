#include <iostream>
#include <map>
#include <vector>
using namespace std;

int Maxpointscard(vector<int> v, int k){
    int lsum=0, rsum=0, maxsum=0;
    for(int i=0; i<k; i++) lsum += v[i];
    maxsum = lsum;

    int rindex = v.size()-1;
    for(int i=k-1; i>=0; i--){
        lsum -= v[i];
        rsum += v[rindex];
        rindex--;
        maxsum = max(maxsum, lsum+rsum);
    }
    return maxsum;
}

int main(){
    vector<int> v;
    int n,e,k;
    cout << "Enter n and k: ";
    cin >> n >> k;
    cout << "Enter elements: ";
    for(int i=0;i<n;i++){
        cin >> e;
        v.push_back(e);
    }
    cout << "MAXIMUM POINTS FROM CARDS: " << Maxpointscard(v,k);
}