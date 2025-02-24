Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.


Code:

class Solution {
public:
    // bool fun(int idx,vector<int> &nums,int t,vector<vector<int>> &dp){
    //     if(idx==0){
    //         return nums[idx]==t;
    //     }
    //     if(t==0) return 1;
    //     if(dp[idx][t]!=-1) return dp[idx][t];
    //     bool not_take=fun(idx-1,nums,t,dp);
    //     bool take=0;
    //     if(nums[idx]<=t){
    //         take=fun(idx-1,nums,t-nums[idx],dp);
    //     }
    //     return dp[idx][t]=not_take||take;
    // }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];
        int t=sum/2;
        if(sum%2) return 0;
        vector<vector<int>> dp(n,vector<int>(t+1,0));
        for(int i=0;i<n;i++) dp[i][0]=1;
        if(nums[0]==t) dp[0][nums[0]]=1;
        for(int i=1;i<n;i++){
            for(int j=1;j<=t;j++){
                bool not_take=dp[i-1][j];
                bool take=(nums[i]<=j)?dp[i-1][j-nums[i]]:0;
                dp[i][j]=not_take||take;
            }
        }
        return dp[n-1][t];
    }
};
