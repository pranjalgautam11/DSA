#include <iostream>
using namespace std;

class DiagonalMatrix{
    private: 
        int n;
        int *A;
    public:
        DiagonalMatrix(int n){
            this->n = n;
            A = new int[n];
        }
        void set(int r,int c,int e);
        int get(int r,int c);
        void display();
};

void DiagonalMatrix::set(int r,int c,int e){
    if(r==c) A[r-1]=e;
}

int DiagonalMatrix::get(int r,int c){
    if(r==c) return A[r-1];
    return 0;
}

void DiagonalMatrix::display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) cout << A[i] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}

int main(){
    DiagonalMatrix d(4);
    cout << "\nSetting elements...\n";
    d.set(1,1,6);
    d.set(2,2,7);
    d.set(3,3,8);
    d.set(4,4,9);

    cout << "\nGetting elements...\n";
    cout << "Element at 1,2: " << d.get(1,2) << endl;
    cout << "Element at 3,3: " << d.get(3,3) << endl;
    cout << "Element at 2,4: " << d.get(2,4) << endl;
    cout << "Element at 4,4: " << d.get(4,4) << endl;

    cout << "\nDisplaying elements...\n";
    d.display();
}