Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency
 of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []

Code: 

class Solution {
public:
    void fun(int idx,int t,vector<int> &nums,vector<int> temp,vector<vector<int>> &res){
        if(t==0){
            res.push_back(temp);
            return ;
        }
        if(idx>=nums.size()) return;
        if(nums[idx]<=t){
            temp.push_back(nums[idx]);
            fun(idx,t-nums[idx],nums,temp,res);
            temp.pop_back();
        }
        fun(idx+1,t,nums,temp,res);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int t) {
        int n=nums.size();
        vector<int> temp;
        vector<vector<int>> res;
        fun(0,t,nums,temp,res);
        return res;
    }
};