#include <iostream>
#include <vector>
using namespace std;

int DeleteMaxHeap(vector<int> &A, int n) {
    if (n <= 0) return -1; 
    int val = A[0]; 
    A[0] = A[n-1];    
    A[n-1] = val;        
    int i=0;
    int j=1; 
    while (j<n-1) {
        if (j+1<n-1 && A[j+1]>A[j]) j = j+1; 
        if (A[i] >= A[j])  break;
        swap(A[i], A[j]);
        i = j;
        j = 2*j + 1;
    }
    return val;   
}

void display(vector<int> &v, int n){
    for(int i=0; i<n; i++) cout << v[i] << " ";
}

int main() {
    vector<int> A = {40, 25, 35, 10, 5, 20, 30};
    int n = A.size();
    cout << "Max heap before sorting...\n";
    display(A, n);
    cout << "\n\nSorting using heap sort...\n";
    for(int i = n; i > 0; i--)  int max = DeleteMaxHeap(A, i);
    display(A, n);
    return 0;
}





