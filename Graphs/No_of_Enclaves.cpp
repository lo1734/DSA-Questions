You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
Code:

class Solution {
public:
    vector<int> roww={-1,1,0,0};
    vector<int> coll={0,0,-1,1};
    void dfs(int i,int j,vector<vector<int>> &mat){
        int n=mat.size();
        int m=mat[0].size();
        mat[i][j]=2;
        for(int k=0;k<4;k++){
            int r=i+roww[k];
            int c=j+coll[k];
            if(r>=0&&c>=0&&r<n&&c<m&&mat[r][c]==1){
                dfs(r,c,mat);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int res=0;
        for(int j=0;j<m;j++){
            if(mat[0][j]==1) dfs(0,j,mat);
            if(mat[n-1][j]==1) dfs(n-1,j,mat);
        }
        for(int i=0;i<n;i++){
            if(mat[i][0]==1) dfs(i,0,mat);
            if(mat[i][m-1]==1) dfs(i,m-1,mat);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    res++;
                } 
                else mat[i][j]=1;
            }
        }
        return res;
    }
};

Optimised using bfs:

class Solution {
public:
    vector<int> roww={-1,1,0,0};
    vector<int> coll={0,0,-1,1};
    int numEnclaves(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int res=0;
        queue<pair<int,int>> q;
        for(int j=0;j<m;j++){
            if(mat[0][j]==1) {
                q.push({0,j});
                mat[0][j]=2;
            }
            if(mat[n-1][j]==1) {
                q.push({n-1,j});
                mat[n-1][j]=2;
            }
        }
        for(int i=0;i<n;i++){
            if(mat[i][0]==1) {
                q.push({i,0});
                mat[i][0]=2;
            }
            if(mat[i][m-1]==1) {
                q.push({i,m-1});
                mat[i][m-1]=2;
            }
        }
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nr=r+roww[k];
                int nc=c+coll[k];
                if(nr>=0&&nc>=0&&nr<n&&nc<m&&mat[nr][nc]==1){
                    mat[nr][nc]=2;
                    q.push({nr,nc});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    res++;
                } 
                else mat[i][j]=1;
            }
        }
        return res;
    }
};
