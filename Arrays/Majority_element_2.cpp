Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]


Code:

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int c1=0,k1=0,k2=0,c2=0;
        vector<int> res;
        for(int i=0;i<n;i++){
            if(c1==0&&k2!=nums[i]){
                k1=nums[i];
                c1=1;
            }
            else if(c2==0&&k1!=nums[i]){
                k2=nums[i];
                c2=1;
            }
            else if(k1==nums[i]) c1++;
            else if(k2==nums[i]) c2++;
            else{
                c1--;
                c2--;
            }
        }
        
        c1=c2=0;
        for(int i=0;i<n;i++){
            if(k1==nums[i]) c1++;
            else if(k2==nums[i]) c2++;
        }
        if(c1>n/3) res.push_back(k1);
        if(c2>n/3) res.push_back(k2);
        return res;
    }
};
