#include <iostream>
#include <vector>
using namespace std;

void InsertMaxHeap(vector<int> &v,int key){
    int i=v.size();
    v.push_back(key);
    while(i>0 && key > v[i%2==0 ? (i/2)-1 : i/2]){
        v[i] = v[i%2 == 0 ? (i/2)-1 : i/2];
        i= i%2 == 0 ? (i/2)-1 : i/2;
    }
    v[i] = key;
}

void CreateMaxHeap(vector<int>& v, int A[], int n){
    for (int i=0; i<n; i++) InsertMaxHeap(v, A[i]);
}

void display(vector<int> &v, int n){
    for(int i=0;i<n;i++) cout << v.at(i) << " ";
}

int main(){
    int a[] = {10, 20, 30, 25, 5, 40, 35};
    int n = sizeof(a)/sizeof(a[0]);
    vector<int> v;
    cout << "\nCreating max heap...\n";
    CreateMaxHeap(v,a,n);
    cout << "\nMax heap...\n";
    display(v,v.size());
}