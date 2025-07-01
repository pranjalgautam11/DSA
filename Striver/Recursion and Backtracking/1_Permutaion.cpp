#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    void calculate(vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds, vector<bool>& visited){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(!visited[i]){
                visited[i] = true;
                ds.push_back(nums[i]);
                calculate(nums, ans, ds, visited);
                ds.pop_back();
                visited[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> visited(nums.size(), false);
        calculate(nums, ans, ds, visited);
        return ans;
    }
};