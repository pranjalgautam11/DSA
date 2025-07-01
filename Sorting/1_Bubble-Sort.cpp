#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &v, int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(v[j]>v[j+1]) swap(v[j],v[j+1]);
        }
    }
}

int bubbleSortAdaptive(vector<int> &v, int n){
    int flag,pass=0;
    for(int i=0;i<n-1;i++){
        flag=0;
        pass++;
        for(int j=0;j<n-1-i;j++){   
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
                flag=1;
            }
        }
        if(flag==0) break;
    }
    return pass;
}

void display(vector<int> v, int n){
    for(int e: v) cout << e << " ";
    cout << endl;
}

int main(){
    vector<int> v = {10,4,2,19,21,32};
    vector<int> v2 = {8,7,10,12,19,29};
    int n = v.size();

    cout << "BUBBLE SORT...\n";
    bubbleSort(v,n);
    display(v,n);

    cout << "\nADAPTIVE BUBBLE SORT...\n";
    cout << "Number of passes: " << bubbleSortAdaptive(v2,n) << endl;
    display(v2,n);
}