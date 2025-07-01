#include <iostream>
#include <vector>
using namespace std;

void DFS(int G[7][7],int start,int n,int visited[7]){
    if(visited[start]==0){
        cout << start << " ";
        visited[start]=1;
            for(int j=1;j<n;j++){
            if(G[start][j]==1 && visited[j]==0) DFS(G,j,n,visited);
        }
    }
}

int main(){
    int G[7][7] = {{0,0,0,0,0,0,0},
                   {0,0,1,1,0,0,0},
                   {0,1,0,0,1,0,0},
                   {0,1,0,0,1,0,0},
                   {0,0,1,1,0,1,1},
                   {0,0,0,0,1,0,0},
                   {0,0,0,0,1,0,0}};
    int visited[7]={0};
    cout << "DFS...\n";
    DFS(G,3,7,visited);
}