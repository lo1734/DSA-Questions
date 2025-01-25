Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15


Code:

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int t) {
        int n=nums.size();
        int l=0,r=0,sum=0;
        int res=0;
        unordered_map<int,int> mp;
        while(r<n){
            sum+=nums[r];
            if(sum==t) res++;
            if(mp.find(sum-t)!=mp.end()){
                res+=mp[sum-t];
            }
            mp[sum]++;
            r++;
        }
        return res;
    }
};
