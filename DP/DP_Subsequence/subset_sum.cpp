Given an array of positive integers arr[] and a value target, determine if there is a subset of the given array with sum equal to given target. 

Examples:

Input: arr[] = [3, 34, 4, 12, 5, 2], target = 9
Output: true 
Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.
Input: arr[] = [3, 34, 4, 12, 5, 2], target = 30
Output: false
Explanation: There is no subset with target sum 30.
Input: arr[] = [1, 2, 3], sum = 6
Output: true
Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.

Code:

class Solution {
  public:
    // bool fun(int idx,vector<int> &arr,int t,vector<vector<int>>&dp){
    //     int n=arr.size();
    //     if(idx==0){
    //         return arr[idx]==t||t==0; 
    //     }
    //     if(t==0) return 1;
    //     if(dp[idx][t]!=-1) return dp[idx][t];
    //     bool not_take=fun(idx-1,arr,t,dp);
    //     bool take=0;
    //     if(arr[idx]<=t){
    //         take=fun(idx-1,arr,t-arr[idx],dp);
    //     }
    //     return dp[idx][t]=not_take||take;
    // }
    bool isSubsetSum(vector<int>& arr, int t) {
        // code here
        int n=arr.size();
        vector<vector<bool>> dp(n,vector<bool>(t+1,0));
        for(int i=0;i<n;i++) dp[i][0]=1;
        if(arr[0]<=t) dp[0][arr[0]]=1;
        for(int i=1;i<n;i++){
            for(int j=1;j<=t;j++){
                bool not_take=dp[i-1][j];
                bool take=(arr[i]<=j)?dp[i-1][j-arr[i]]:0;
                dp[i][j]=not_take||take;
            }
        }
        return dp[n-1][t];
    }
};
