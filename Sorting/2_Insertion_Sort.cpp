#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &v,int n){
    int swap=0;
    for(int i=1;i<n;i++){
        int j=i-1;
        int e = v[i];
        while(j>-1 && v[j]>e){
            v[j+1]=v[j];
            swap++;
            j--;
        }
        v[j+1]=e;
    }
    cout << swap << endl;
}

void display(vector<int> v, int n){
    for(int e: v) cout << e << " ";
    cout << endl;
}

int main(){
    vector<int> v = {10,4,2,19,6,12};
    vector<int> v2 = {3,7,9,12,17,29};
    int n = v.size();

    cout << "INSERTION SORT...\n";
    cout << "Number of swaps: ";
    insertionSort(v,n);
    display(v,n);

    cout << "\nINSERTION SORT on SORTED ARRAY...\n";
    cout << "Number of swaps: ";
    insertionSort(v2,n);
    display(v2,n);
}