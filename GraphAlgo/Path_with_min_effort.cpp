You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

Example 1:



Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
Example 2:



Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
Example 3:


Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.

Code:

class Solution {
public:
    vector<int> roww={-1,1,0,0};
    vector<int> coll={0,0,-1,1};
    int minimumEffortPath(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int res=INT_MAX;
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>> > pq;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(!pq.empty()){
            int diff=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(r==n-1&&c==m-1){
                return diff;
            }
            for(int i=0;i<4;i++){
                int nr=r+roww[i];
                int nc=c+coll[i];
                if(nr>=0&&nc>=0&&nr<n&&nc<m){
                    int new_effort=max(abs(mat[nr][nc]-mat[r][c]),diff);
                    if(new_effort<dist[nr][nc]){
                        dist[nr][nc]=new_effort;
                        pq.push({dist[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};
