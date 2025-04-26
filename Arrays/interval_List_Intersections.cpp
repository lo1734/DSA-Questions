You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.

The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].

Code:

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<vector<int>> res;
        if(n1==0||n2==0) return res;
        int i=0,j=0;
        while(i<n1&&j<n2){
            int s1=nums1[i][0];
            int s2=nums2[j][0];
            int e1=nums1[i][1];
            int e2=nums2[j][1];
            if(s1<=e2&&s2<=e1){
                res.push_back({max(s1,s2),min(e1,e2)});
            }
            if(e1<e2) i++;
            else j++;
        }
        return res;
    }
};
