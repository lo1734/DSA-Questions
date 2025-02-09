Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

Code:

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int k=nums[0];
        int cnt=1;
        for(int i=0;i<n;i++){
            if(nums[i]==k){
                cnt++;
            }
            else{
                cnt--;
                if(cnt==0){
                    k=nums[i];
                    cnt=1;
                }
            }
        }
        cnt==0;
        for(int i=0;i<n;i++){
            if(nums[i]==k) cnt++;
        }
        if(cnt>n/2) return k;
        return -1;
    }
};
