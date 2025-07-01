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

void display(vector<int> &v, int n){
    for(int i=0;i<n;i++) cout << v.at(i) << " ";
}

int main(){
    vector<int> v = {45,35,30,10,6,20};
    cout << "\nInserting in max heap...\n";
    InsertMaxHeap(v,50);
    InsertMaxHeap(v,38);
    cout << "Max heap after insert...\n";
    display(v,v.size());
}