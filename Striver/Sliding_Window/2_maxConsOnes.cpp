#include <bits/stdc++.h>
using namespace std;

int maxConsecutiveOnesAfterFlippingKBits(vector<int> v, int k){
    int l=0,r=0,maxlen=0,zeroes=0;
    while(r<v.size()){
        if(v[r]==0) zeroes++;
        if(zeroes>k){
            if(v[l]==0) zeroes--;
            l++;
        }
        if(zeroes<=k){
            int len=r-l+1;
            maxlen=max(len,maxlen);
        }
        r++;
    }
    return maxlen;
}

int main(){
    vector<int> v;
    int n,k,e;
    cout << "Enter n and k: ";
    cin >> n >> k;
    cout << "Enter elements: ";
    for(int i=0;i<n;i++){
        cin >> e;
        v.push_back(e);
    }
    cout << "MAX CONSECUTIVE ONES: " << maxConsecutiveOnesAfterFlippingKBits(v,k);
}