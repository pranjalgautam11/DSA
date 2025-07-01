#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &v,int l,int h){
    int pivot=v[l];
    int i=l+1;
    int j=h;
    while(true){
        while(i<=j && v[i]<=pivot) i++;
        while(j>=i && v[j]>=pivot) j--;
        if(i>j) break;
        else swap(v[i],v[j]);
    }
    swap(v[l],v[j]);
    return j;
}

void quickSort(vector<int> &v,int l,int h){
    if(l<h){
        int p = partition(v,l,h);
        quickSort(v,l,p-1);
        quickSort(v,p+1,h);
    }
}

void display(vector<int> v, int n){
    for(int e: v) cout << e << " ";
    cout << endl;
}

int main(){
    vector<int> v = {10,4,2,19,6,12,5,9};
    int n = v.size();

    cout << "QUICK SORT USING FIRST ELEMENT AS PIVOT...\n";
    quickSort(v,0,n-1);
    display(v,n);
}