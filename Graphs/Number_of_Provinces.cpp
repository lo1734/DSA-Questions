Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

Code:

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int src,vector<int> &vis,vector<vector<int>> &graph){
        vis[src]=1;
        for(auto it:graph[src]){
            if(!vis[it]){
                dfs(it,vis,graph);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int n) {
        // code here
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj[i][j]==1){
                    graph[i].push_back(j);
                }
            }
        }
        vector<int> vis(n,0);
        int res=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,graph);
                res++;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends
