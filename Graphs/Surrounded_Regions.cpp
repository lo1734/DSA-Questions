You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

 

Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Code:

class Solution {
public:
    vector<int> roww={-1,1,0,0};
    vector<int> coll={0,0,-1,1};
    void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<char>>& mat){
        int n=mat.size();
        int m=mat[0].size();
        vis[i][j]=1;
        mat[i][j]='a';
        for(int k=0;k<4;k++){
            int r=i+roww[k];
            int c=j+coll[k];
            if(r>=0&&c>=0&&r<n&&c<m&&!vis[r][c]&&mat[r][c]=='O'){
                dfs(r,c,vis,mat);
            }
        }
    }
    void solve(vector<vector<char>>& mat){
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(mat[0][j]=='O') dfs(0,j,vis,mat);
            if(mat[n-1][j]=='O') dfs(n-1,j,vis,mat);
        }
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O') dfs(i,0,vis,mat);
            if(mat[i][m-1]=='O') dfs(i,m-1,vis,mat);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='a') mat[i][j]='O';
                else mat[i][j]='X';
            }
        }
    }
};
