Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.


Code:

class Solution {
public:
    vector<int> roww={-1,-1,-1,1,1,1,0,0};
    vector<int> coll={-1,0,1,-1,0,1,-1,1};
    int shortestPathBinaryMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int res=0;
        vector<vector<int>> vis(n,vector<int>(n,0));
        queue<pair<int,pair<int,int>>> q;
        if(mat[0][0]==1||mat[n-1][n-1]==1) return -1;
        q.push({1,{0,0}});
        while(!q.empty()){
            int steps=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            if(r==n-1&&c==n-1) return steps;
            for(int i=0;i<8;i++){
                int nr=r+roww[i];
                int nc=c+coll[i];
                if(nr>=0&&nc>=0&&nr<n&&nc<n&&mat[nr][nc]==0&&!vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({steps+1,{nr,nc}});
                }
            }
        }
        return -1;
    }
};
