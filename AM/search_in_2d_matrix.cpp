You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Code:

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int n=mat.size();
        int m=mat[0].size();
        int l=0,r=m*n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int row=mid/m,col=mid%m;
            if(mat[row][col]==t) return 1;
            else if(mat[row][col]>t) r=mid-1;
            else l=mid+1;
        }
        return 0;
    }
};
