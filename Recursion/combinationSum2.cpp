Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

code:

class Solution {
public:
    //[10,1,2,7,6,1,5]
    //[1,1,2,5,6,7,10]
    void fun(int idx,int t,vector<int> &nums,vector<int> temp,vector<vector<int>> &res){
        if(t<0) return;
        if(t==0){
            res.push_back(temp);
            return ;
        }
        for(int i=idx;i<nums.size();i++){
            if(i>idx&&nums[i]==nums[i-1]) continue;
            if(nums[i]>t) break;

            temp.push_back(nums[i]);
            fun(i+1,t-nums[i],nums,temp,res);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int t) {
        vector<int> temp;
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        fun(0,t,nums,temp,res);
        return res;
    }
};
