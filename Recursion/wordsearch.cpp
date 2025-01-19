// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. 
//  The same letter cell may not be used more than once.

 
class Solution {
public:
    vector<int> roww={0,0,-1,1};
    vector<int> coll={-1,1,0,0};
    bool fun(int i,int j,int idx,vector<vector<int>> &vis,vector<vector<char>> &mat,string &w){
        int n=mat.size();
        int m=mat[0].size();
        if(idx==w.length()) return 1;
        if(i<0||j<0||i>=n||j>=m||mat[i][j]!=w[idx]||vis[i][j]) {
            return 0;
        }
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int nr=i+roww[k];
            int nc=j+coll[k];
                if (fun(nr, nc, idx + 1, vis, mat, w)) {
                    return 1;
                }
            
        }
        vis[i][j]=0;
        return 0;
    }
    bool exist(vector<vector<char>>& mat, string w) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        if(w.length()==1){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(mat[i][j]==w[0]) return 1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(fun(i,j,0,vis,mat,w)) return 1;
            }
        }
        return 0;
    }
};
