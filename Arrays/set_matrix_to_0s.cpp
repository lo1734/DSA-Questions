Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

Code:
class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int c0=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    mat[i][0]=0;
                    if(j!=0){
                        mat[0][j]=0;
                    }
                    else c0=0;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[i][0]==0||mat[0][j]==0){
                    mat[i][j]=0;
                }
            }
        }
        if(mat[0][0]==0){
            for(int j=1;j<m;j++){
                mat[0][j]=0;
            }
        }
        if(c0==0){
            for(int i=0;i<n;i++){
                mat[i][0]=0;
            }
        }
    }
};
