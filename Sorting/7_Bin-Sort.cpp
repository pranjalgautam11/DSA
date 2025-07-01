#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
        int value;
        Node* next;
};

int max(vector<int> v,int n){
    int m = INT32_MIN;
    for(int i=0;i<n;i++){
        if(v[i]>m) m=v[i];
    }
    return m;
}

void Insert(Node** bins, int ind){
    Node* temp = new Node;
    temp->value = ind;
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

void binSort(vector<int> &v,int n){
    int m = max(v, n);
    Node** bins = new Node*[m + 1];
    for (int i=0; i<m+1; i++) bins[i] = NULL;
    for (int i=0; i<n; i++) Insert(bins, v[i]);
    int i=0,j=0;
    while (i<m+1){
        while (bins[i] != NULL){
            v[j++] = Delete(bins, i);
        }
        i++;
    }
}

void display(vector<int> v, int n){
    for(int e: v) cout << e << " ";
    cout << endl;
}

int main(){
    vector<int> v = {10,4,2,19,25,12,1,7};
    int n = v.size();

    cout << "BIN/BUCKET SORT...\n";
    binSort(v,n);
    display(v,n);
}