Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

Code:

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> res;
        int n=mat.size();
        int m=mat[0].size();
        int top=0,bottom=n-1,left=0,right=m-1;
        while(top<=bottom&&left<=right){
            for(int j=left;j<=right;j++){
                res.push_back(mat[top][j]);
            }
            top++;
            for(int i=top;i<=bottom;i++){
                res.push_back(mat[i][right]);
            }
            right--;
            if(top<=bottom){
                for(int j=right;j>=left;j--){
                    res.push_back(mat[bottom][j]);
                }
            }
            bottom--;
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    res.push_back(mat[i][left]);
                }
            }
            left++;
        }
        return res;
    }
};
