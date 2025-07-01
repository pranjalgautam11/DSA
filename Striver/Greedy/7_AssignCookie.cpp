#include <bits/stdc++.h>
using namespace std;

int AssignCookie(vector<int> &greed, vector<int> &size) {
    int n = greed.size(), m = size.size(), l=0, r=0;
    sort(greed.begin(), greed.end());
    sort(size.begin(), size.end());

    while(l<m){
        if(greed[r] <= size[l])
            r++;
        l++;
    }
    return r;
}

int main(){
    vector<int> greed = {1,5,3,3,4};
    vector<int> size = {4,2,1,2,1,3};
    cout << "The Total Cookie can be assigned are: " << AssignCookie(greed,size);
}
