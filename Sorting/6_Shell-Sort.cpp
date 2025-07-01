#include <iostream>
#include <vector>
using namespace std;

void shellSort(vector<int> &v, int n){
    for (int gap=n/2; gap>=1; gap/=2){
        for (int j=gap; j<n; j++){
            int temp = v[j];
            int i = j - gap;
            while (i >= 0 && v[i] > temp){
                v[i+gap] = v[i];
                i = i-gap;
            }
            v[i+gap] = temp;
        }
    }
}

void display(vector<int> v, int n){
    for(int e: v) cout << e << " ";
    cout << endl;
}

int main(){
    vector<int> v = {11,13,7,1,16,9,24,5,2,10};
    int n = v.size();

    cout << "SHELL SORT...\n";
    shellSort(v,n);
    display(v,n);
}