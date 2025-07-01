#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int lessequalto(vector<int> &num, int goal){
    if(goal<0) return 0;

    int l=0, r=0, sum=0, count=0;
    while(r<=num.size()){
        sum += num[r];
        while(sum > goal){ // for sum<=g 
            sum -= num[l];
            l++;
        }
        count += (r-l+1);
        r++;
    }
    return count;
}

int binSubarrWithSum(vector<int> &v, int g){
    return lessequalto(v,g)-lessequalto(v,g-1);
}

int main(){
    int n, goal;
    vector<int> num;
    cout << "Enter the n and goal: ";
    cin >> n >> goal;
    cout << "Enter the number: ";
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        num.push_back(a);
    } 
    cout << "Total subarray: " << binSubarrWithSum(num,goal);
}