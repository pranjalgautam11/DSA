#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> &v,int l,int m,int h){
    int i=l,j=m+1,k=l;
    vector<int> w(v.size()+1);
    while(i<=m && j<=h){
        if(v[i]<v[j]) w[k++]=v[i++];
        else w[k++]=v[j++];
    }
    while(i<=m) w[k++]=v[i++];
    while(j<=h) w[k++]=v[j++];
    for(int i=l;i<=h;i++) v[i]=w[i];
}

void mergeSortIterative(vector<int> &v,int n){
    int p;
    for(p=2;p<=n;p*=2){
        for(int i=0;i<n;i+=p){
            int l=i;
            int h=min(i+p-1,n-1);
            int m=l+(h-l)/2;
            Merge(v,l,m,h);
        }
    }
    if(p/2<n) Merge(v,0,(p/2)-1,n-1);
}

void mergeSortRecursive(vector<int> &v,int l,int h){
    int m;
    if(l<h){
        m=(l+h)/2;
        mergeSortRecursive(v,l,m);
        mergeSortRecursive(v,m+1,h);
        Merge(v,l,m,h);
    }
}

void display(vector<int> v, int n){
    for(int e: v) cout << e << " ";
    cout << endl;
}

int main(){
    vector<int> v = {10,4,2,15,6,12,9};
    int n = v.size();

    cout << "ITERATIVE MERGE SORT...\n";
    mergeSortIterative(v,n);
    display(v,n);

    cout << "\nRECURSIVE MERGE SORT...\n";
    mergeSortRecursive(v,0,6);
    display(v,n);
}