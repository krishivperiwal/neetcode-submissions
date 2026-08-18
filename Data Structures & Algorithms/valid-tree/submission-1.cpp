class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n - 1 != edges.size())return false;
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0,adj,vis);
        for(int i = 0; i < n; i++){
            if(!vis[i])return false;
        }
        return true;
    }  

    void dfs(int node,vector<vector<int>>& adj,vector<int>& vis){
        vis[node] = 1;

        for(auto nei:adj[node]){
            if(!vis[nei]){
                dfs(nei,adj,vis);
            }
        }
    }
};
