#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Minplatform(vector<int> arr, vector<int> dep){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    int platform = 1, result = 1, i=1, j=0; // Start i from the second element and j from the first

    while(i<n && j<n){
        if(arr[i]<=dep[j]){
            platform++;
            i++;
        }
        else{ // arr[i] > dep[j];
            platform--;
            j++;
        }
        if(platform > result)
            result = platform;
    }
    
    return result;
}

int main(){
    vector<int> arr = {900,945,955,1100,1500,1800};
    vector<int> dep ={920,1200,1130,1150,1900,2000};
    cout<< "Minimum number of Platforms required: "<< Minplatform(arr,dep)<< endl;
}