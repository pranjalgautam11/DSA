#include <iostream>
#include <vector>
using namespace std;

int DeleteMaxHeap(vector<int> &A, int n) {
    if (n <= 0) return -1; 
    int val = A[0]; 
    A[0] = A[n-1];  
    n--;           
    int i=0;
    int j=2*i+1; 
    while (j<n) {
        if (j+1<n && A[j+1]>A[j]) j=j+1; 
        if (A[i]>=A[j])  break;
        swap(A[i], A[j]);
        i=j;
        j=2*i+1;
    }
    A.pop_back(); 
    return val;   
}

void display(vector<int> &v, int n){
    for(int i=0;i<n;i++) cout << v.at(i) << " ";
}

int main() {
    vector<int> A = {40, 25, 35, 10, 5, 20, 30};
    cout << "Max heap before delete...\n";
    display(A,A.size());
    cout << "\n\nDeleting in max heap...\n";
    cout << "Deleted: " << DeleteMaxHeap(A, A.size()) << endl;
    cout << "Deleted: " << DeleteMaxHeap(A, A.size()) << endl;
    cout << "\nMax heap after delete...\n";
    display(A,A.size());
    return 0;
}
