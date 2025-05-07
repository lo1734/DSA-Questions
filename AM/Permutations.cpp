Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]

Code:
class Solution {
public:
    void fun(int idx,vector<int> &nums,vector<vector<int>> &res){
        if(idx==nums.size()){
            res.push_back({nums});
            return;
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            fun(idx+1,nums,res);
            swap(nums[i],nums[idx]);
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> res;
        vector<int> temp;
        fun(0,nums,res);
        return res;
    }
};]
