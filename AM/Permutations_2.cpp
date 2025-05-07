Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]i

Code:

class Solution {
public:
    void fun(int i,int j,vector<int> nums,vector<vector<int>> &res){
        if(i==j-1){
            res.push_back({nums});
            return ;
        }
        for(int k=i;k<j;k++){
            if(i!=k&&nums[i]==nums[k]) continue;
            swap(nums[i],nums[k]);
            fun(i+1,j,nums,res);   
            // swap(nums[i],nums[k]); 
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        fun(0,n,nums,res);
        return res;
    }
};
