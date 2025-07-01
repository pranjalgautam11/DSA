#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void FindCombination(int index, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
        if(index == arr.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }

        if(arr[index] <= target){
            ds.push_back(arr[index]);
            FindCombination(index, target-arr[index], arr, ans, ds);
            ds.pop_back();
        }
        FindCombination(index+1, target, arr, ans, ds);
    }
    public: 
        vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        FindCombination(0, target, candidates, ans, ds);
        return ans;
    }
};

int main(){
    Solution obj;
    vector<int> v {2,3,6,7};
    int target = 7;

    vector<vector<int>> ans = obj.combinationSum(v, target);
    cout << "Combinations are: " << endl;
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
  }
}