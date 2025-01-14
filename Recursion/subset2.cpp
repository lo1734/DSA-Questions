Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]

code:

class Solution {
public:
    void fun(int idx,vector<int> &nums,vector<int> temp,vector<vector<int>> &res){
        res.push_back(temp);
        for(int i=idx;i<nums.size();i++){
            if(i>idx&&nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            fun(i+1,nums,temp,res);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        fun(0,nums,temp,res);
        return res;
    }
};
