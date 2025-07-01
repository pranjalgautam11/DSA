#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Node{
    public:
        int value;
        Node* next;
};

void Insert(Node** bins, int value, int ind){
    Node* temp = new Node;
    temp->value = value;
    temp->next = NULL;
    if (bins[ind] == NULL) bins[ind] = temp; 
    else {
        Node* p = bins[ind];
        while (p->next != NULL) p = p->next;
        p->next = temp;
    }
}

int Delete(Node** bins, int ind){
    Node* p = bins[ind];  
    bins[ind] = bins[ind]->next;
    int x = p->value;
    delete p;
    return x;
}

int digits(int x){
    int d=0;
    while(x!=0){
        x/=10;
        d++;
    }
    return d;
}

int max(vector<int> v,int n){
    int m = INT32_MIN;
    for(int i=0;i<n;i++){
        if(v[i]>m) m=v[i];
    }
    return m;
}

int getBinIndex(int x, int ind){
    return (int)(x / pow(10, ind)) % 10;
}

void radixSort(vector<int> &v, int n){
    int m = max(v, n);
    int nPass = digits(m);
    Node** bins = new Node* [10];
    for (int i=0; i<10; i++) bins[i] = NULL;
    for (int pass=0; pass<nPass; pass++){
        for (int i=0; i<n; i++){
            int binind = getBinIndex(v[i], pass);
            Insert(bins, v[i], binind);
        }
        int i = 0,j = 0;
        while (i < 10){
            while (bins[i] != NULL){
                v[j++] = Delete(bins, i);
            }
            i++;
        }
        for (int i=0; i<10; i++) bins[i] = NULL;
    }
}

void display(vector<int> v, int n){
    for(int e: v) cout << e << " ";
    cout << endl;
}

int main(){
    vector<int> v = {10,4,2,19,25,12,1,7};
    int n = v.size();

    cout << "RADIX SORT...\n";
    radixSort(v,n);
    display(v,n);
}