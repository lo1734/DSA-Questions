You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Code:

class Solution {
public:
    vector<int> roww={-1,1,0,0};
    vector<int> coll={0,0,-1,1};
    int orangesRotting(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int fresh=0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==2) q.push({i,j});
                if(mat[i][j]==1) fresh++;
            }
        }
        int res=0;
        if(fresh==0) return res;
        while(!q.empty()){
            int k=q.size();
            bool flag=0;
            for(int i=0;i<k;i++){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nr=r+roww[i];
                    int nc=c+coll[i];
                    if(nr>=0&&nc>=0&&nr<n&&nc<m&&mat[nr][nc]==1){
                        mat[nr][nc]=2;
                        q.push({nr,nc});
                        fresh--;
                        flag=1;
                    }
                }
            }
            if(flag) res++;
        }
        if(fresh==0) return res;
        return -1;
    }
};
