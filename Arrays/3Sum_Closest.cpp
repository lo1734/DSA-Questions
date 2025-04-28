Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) {
        int n=nums.size();
        int res=0,diff=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int l=i+1,r=n-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if(sum>=t) r--;
                else if(sum<t) l++;
                if(abs(t-sum)<diff){
                    diff=abs(t-sum);
                    res=sum;
                }
            }
        }
        return res;
    }
};
