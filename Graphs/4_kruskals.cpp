#include <iostream>
#define I 32767 
#define V 7 
#define E 9  
using namespace std;
 
void display(int T[][V-1], int A[][E]){
    cout << "\nMinimum Cost Spanning Tree Edges\n" << endl;
    int sum=0;
    for (int i=0; i<V-1; i++){
        cout  << T[0][i] << "->" << T[1][i] << endl;
        for (int j = 0; j < E; j++){
                if ((A[0][j]==T[0][i] && A[1][j]==T[1][i]) || (A[0][j]==T[1][i] && A[1][j]==T[0][i])){
                    sum += A[2][j];
                    break;
                }
        }
    }
    cout << endl;
    cout << "Total cost of MST: " << sum << endl;
}
 
void Union(int u, int v, int s[]){
    if (s[u] < s[v]){
        s[u] += s[v];
        s[v] = u;
    } 
    else {
        s[v] += s[u];
        s[u] = v;
    }
}
 
int Find(int u, int s[]){
    int x = u;
    int v = 0;
    while (s[x] > 0) x = s[x];
    while (u != x){
        v = s[u];
        s[u] = x;
        u = v;
    }
    return x;
}
 
void KruskalsMCST(int A[3][9]){
    int T[2][V-1];  
    int included[E] = {0}; 
    int set[V+1] = {-1, -1, -1, -1, -1, -1, -1, -1}; 
    int i=0;
    while (i < V-1){
        int min = I;
        int u=0,v=0,k=0;
        for (int j=0; j<E; j++){
            if (included[j] == 0 && A[2][j] < min){
                min = A[2][j];
                u = A[0][j];
                v = A[1][j];
                k = j;
            }
        }
        if (Find(u, set) != Find(v, set)){
            T[0][i] = u;
            T[1][i] = v;
            Union(Find(u, set), Find(v, set), set);
            i++;
        }
        included[k] = 1;
    }
    display(T, A);
}
 
int main() {
    int edges[3][9] = {{ 1, 1,  2,  2, 3,  4,  4,  5,  5},
                       { 2, 6,  3,  7, 4,  5,  7,  6,  7},
                       {25, 5, 12, 10, 8, 16, 14, 20, 18}};
    KruskalsMCST(edges);
}