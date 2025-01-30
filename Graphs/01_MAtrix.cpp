Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.
Code:

class Solution {
public:
    vector<int> roww={-1,1,0,0};
    vector<int> coll={0,0,-1,1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> res(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int k=q.size();
            for(int i=0;i<k;i++){
                int r=q.front().first.first;
                int c=q.front().first.second;
                int steps=q.front().second;
                q.pop();
                res[r][c]=steps;
                for(int j=0;j<4;j++){
                    int nr=r+roww[j];
                    int nc=c+coll[j];
                    if(nr>=0&&nc>=0&&nr<n&&nc<m&&!vis[nr][nc]&&mat[nr][nc]==1){
                        q.push({{nr,nc},steps+1});
                        vis[nr][nc]=1;
                    }
                }
            }
        }
        return res;
    }
};
