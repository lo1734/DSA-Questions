You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.

 

Example 1:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

Output: [[2,2,2],[2,2,0],[2,0,1]]


Code:

class Solution {
public:
    vector<int> roww={-1,1,0,0};
    vector<int> coll={0,0,-1,1};
    vector<vector<int>> floodFill(vector<vector<int>>& mat, int sr, int sc, int col) {
        int n=mat.size();
        int m=mat[0].size();
        int ocol=mat[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr,sc});
        mat[sr][sc]=col;
        if(ocol==col) return mat;
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int j=0;j<4;j++){
                int nr=r+roww[j];
                int nc=c+coll[j];
                if(nr>=0&&nc>=0&&nr<n&&nc<m&&mat[nr][nc]==ocol){
                    mat[nr][nc]=col;
                    q.push({nr,nc});
                }
            }
        }
        return mat;
    }
};
