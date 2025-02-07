You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Code:

class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n=nums.size();
        int res=0,mini=nums[0];
        for(int i=0;i<n;i++){
            res=max(res,nums[i]-mini);
            mini=min(mini,nums[i]);
        }
        return res;
    }
};
