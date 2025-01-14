// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

// code:

class Solution {
public:
    void fun(int idx,int k,int t,vector<int> &nums,vector<int> temp,vector<vector<int>> &res){
        if(temp.size()==k&&t==0){
            res.push_back(temp);
            return;
        }
        if(idx>=nums.size()) return ;
        temp.push_back(nums[idx]);
        fun(idx+1,k,t-nums[idx],nums,temp,res);
        temp.pop_back();
        fun(idx+1,k,t,nums,temp,res);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> res;
        vector<int> nums={1,2,3,4,5,6,7,8,9};
        fun(0,k,n,nums,temp,res);
        return res;
    }
};
