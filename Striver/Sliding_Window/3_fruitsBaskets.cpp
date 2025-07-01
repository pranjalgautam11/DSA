#include <iostream>
#include <map>
#include <vector>
using namespace std;

int fruitsInBaskets(vector<int> v){
    int l=0,r=0,maxlen=0;
    map<int,int> m;
    while(r<v.size()){
        m[v[r]]++;
        if(m.size()>2){
            m[v[l]]--;
            if(m[v[l]]==0) m.erase(v[l]);
            l++;
        }
        if(m.size()<=2){
            int len=r-l+1;
            maxlen = max(maxlen,len);
        }
        r++;
    }
    return maxlen;
}

int main(){
    vector<int> v;
    int n,e;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter elements: ";
    for(int i=0;i<n;i++){
        cin >> e;
        v.push_back(e);
    }
    cout << "MAXIMUM FRUITS IN 2 BASKETS: " << fruitsInBaskets(v);
}