#include <iostream>
#include <vector>

using namespace std;

vector<int> Mincoins(vector<int> coins, int goal){
    vector<int> ans;
    for(int i=coins.size()-1; i>=0; i--){
        while(goal >= coins[i]){
            goal -= coins[i];
            ans.push_back(coins[i]);
        }
    }
    return ans;
}

int main(){
    vector<int> coins = {1,2,5,10,20,50,100};
    int sum;
    cout << "Enter the sum: "; cin >> sum;
    vector<int> ans = Mincoins(coins,sum);
    for(int ele : ans)
        cout << ele << " ";
}