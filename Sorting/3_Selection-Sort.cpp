#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &v,int n){
    int swaps=0;
    for(int i=0;i<n-1;i++){
        int j,k;
        for(j=k=i;j<n;j++){
            if(v[j]<v[k]) k=j;
        }
        swap(v[i],v[k]);
        swaps++;
    }
    cout << swaps << endl;
}

void display(vector<int> v, int n){
    for(int e: v) cout << e << " ";
    cout << endl;
}

int main(){
    vector<int> v = {10,4,2,19,6,12};
    vector<int> v2 = {3,7,9,12,17,29};
    int n = v.size();

    cout << "SELECTION SORT...\n";
    cout << "Number of swaps: ";
    selectionSort(v,n);
    display(v,n);

    cout << "\nSELECTION SORT on SORTED ARRAY...\n";
    cout << "Number of swaps: ";
    selectionSort(v2,n);
    display(v2,n);
}