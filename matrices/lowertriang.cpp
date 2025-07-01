#include <iostream>
using namespace std;

class LowerTriangular{
    private: 
        int n;
        int *A;
    public:
        LowerTriangular(int n){
            this->n = n;
            A = new int[n*(n+1)/2];
        }
        void set(int r,int c,int e);
        int get(int r,int c);
        void display();
};

// ROW MAJOR MAPPING
void LowerTriangular::set(int r,int c,int e){
    if(r>=c) A[r*(r-1)/2+c-1]=e;
}

int LowerTriangular::get(int r,int c){
    if(r>=c) return A[r*(r-1)/2+c-1];
    return 0;
}

void LowerTriangular::display(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i>=j) cout << A[i*(i-1)/2+j-1] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}

int main(){
    int m;
    cout << "Enter dimensions: ";
    cin >> m;
    LowerTriangular d(m);
    cout << "\nSetting elements...\n";
    int e;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            cin >> e;
            d.set(i,j,e);
        }
    }

    cout << "\nGetting elements...\n";
    cout << "Element at 1,2: " << d.get(1,2) << endl;
    cout << "Element at 3,3: " << d.get(3,3) << endl;
    cout << "Element at 2,1: " << d.get(2,1) << endl;
    cout << "Element at 4,4: " << d.get(4,4) << endl;

    cout << "\nDisplaying elements...\n";
    d.display();
}