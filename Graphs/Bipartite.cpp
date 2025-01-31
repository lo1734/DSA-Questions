There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.

Code:

class Solution {
public:
    bool dfs(int src,int c,vector<int> &col,vector<vector<int>>& adj){
        col[src]=c;
        for(auto it:adj[src]){
            if(col[it]==-1){
                if(!dfs(it,!c,col,adj)) return 0;
            }
            else if(col[it]==c) return 0;
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(!dfs(i,0,col,adj)) return 0;
            }
        }
        return 1;
    }
};
