// Nice Subarray - number of odd numbers equal to given k value

#include <iostream>
#include <vector>
using namespace std;

int lessequalto(vector<int> v, int k){
    if(k<0) return 0;

    int l=0, r=0, sum=0, count=0;
    while(r<=v.size()){
        sum += v[r]%2; // if even->0, odd->1
        while(sum > k){
            sum -= v[l]%2;
            l++;
        }
        count += (r-l+1);
        r++;
    }
    return count;
}

int Nicesubarray(vector<int> &v, int g){
    return lessequalto(v,g)-lessequalto(v,g-1);
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
    cout << "NUMBER OF NICE SUBARRAYS(HAVING K ODD ELEMENTS): " << Nicesubarray(v,k);
}