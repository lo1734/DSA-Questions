// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

// Code:

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        for(auto it:pre){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> res;
        vector<int> indeg(n,0);
        queue<int> q;
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indeg[it]++;
            }
        }
        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }
        while(!q.empty()){
            int k=q.size();
            for(int i=0;i<k;i++){
                int node=q.front();
                res.push_back(node);
                q.pop();
                for(auto it:adj[node]){
                    indeg[it]--;
                    if(indeg[it]==0) q.push(it);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(indeg[i]!=0) return {};
        }
        return res;
    }
};

