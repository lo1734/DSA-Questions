You are given a 0-indexed m x n integer matrix grid consisting of distinct integers from 0 to m * n - 1. You can move in this matrix from a cell to any other cell in the next row. That is, if you are in cell (x, y) such that x < m - 1, you can move to any of the cells (x + 1, 0), (x + 1, 1), ..., (x + 1, n - 1). Note that it is not possible to move from cells in the last row.

Each possible move has a cost given by a 0-indexed 2D array moveCost of size (m * n) x n, where moveCost[i][j] is the cost of moving from a cell with value i to a cell in column j of the next row. The cost of moving from cells in the last row of grid can be ignored.

The cost of a path in grid is the sum of all values of cells visited plus the sum of costs of all the moves made. Return the minimum cost of a path that starts from any cell in the first row and ends at any cell in the last row

Code:

class Solution {
public:
    int fun(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &cost,vector<vector<int>> &dp){
        if(i==grid.size()-1&&j<grid[0].size()){
            return grid[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        int c=grid[i][j];
        for(int k=0;k<cost[c].size();k++){
            int val=c+cost[c][k]+fun(i+1,k,grid,cost,dp);
            mini=min(mini,val);
        }
        return dp[i][j]=mini;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& cost) {
        int n=grid.size();
        int m=grid[0].size();
        int res=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int j=0;j<m;j++){
            int val=fun(0,j,grid,cost,dp);
            res=min(res,val);
        }
        return res;
    }
};.
