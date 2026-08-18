class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> visited(n,0);
        int ans = 0;

        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                ans++;
                dfs(i,visited,adj);
            }
        }

        return ans;
    }

    void dfs(int node,vector<int>& visited,vector<vector<int>>& adj){
        visited[node] = 1;

        for(auto nei:adj[node]){
            if(!visited[nei]){
                dfs(nei,visited,adj);
            }
        }
    }
};
