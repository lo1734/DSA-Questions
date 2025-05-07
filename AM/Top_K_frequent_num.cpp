Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]

Code:

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==n) return nums;
        vector<int> res;
        unordered_map<int,int> mp;
        for(int i:nums){
            mp[i]++;
        }
        vector<pair<int,int>> v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),[](pair<int,int> &a,pair<int,int> &b){
            return a.second>b.second;
        });
        for(int i=0;i<k;i++){
            res.push_back(v[i].first);
        }
        return res;
    }
};
