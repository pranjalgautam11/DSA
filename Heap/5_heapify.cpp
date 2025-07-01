#include <iostream>
using namespace std;
 
void Heapify(int A[], int n){
    for (int i=(n/2)-1; i>=0; i--){
        int j = 2 * i + 1;  
        while(j < n-1){
            if (A[j] < A[j+1]) j = j+1;
            if (A[i] < A[j]){
                 int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                i = j;
                j = 2 * i + 1;
            }
            else break;
        }
    }
}

void display(int A[], int n){
    for(int i=0;i<n;i++) cout << A[i] << " ";
}
 
int main() {
    int A[] = {5, 10, 30, 20, 35, 40, 15};
    int n = sizeof(A)/sizeof(A[0]);
    cout << "\nCreating max heap...\n";
    Heapify(A,n);
    cout << "\nMax heap...\n";
    display(A,n);
}