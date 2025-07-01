#include <iostream>
#include <vector>
using namespace std;

int max(vector<int> v,int n){
    int m = INT32_MIN;
    for(int i=0;i<n;i++){
        if(v[i]>m) m=v[i];
    }
    return m;
}

void countSort(vector<int> &v,int n){
    int m = max(v,n);
    vector<int> c(m+1);
    for(int i=0;i<m+1;i++) c[i]=0;
    for(int i=0;i<n;i++) c[v[i]]++;
    int i=0,j=0;
    while(i<m+1){
        if(c[i]>0){
            v[j++]=i;
            c[i]--;
        }
        else i++;
    }
}

void display(vector<int> v, int n){
    for(int e: v) cout << e << " ";
    cout << endl;
}

int main(){
    vector<int> v = {10,4,2,19,6,25,6,7,6};
    int n = v.size();

    cout << "COUNT SORT...\n";
    countSort(v,n);
    display(v,n);
}