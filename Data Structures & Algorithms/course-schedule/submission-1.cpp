class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(numCourses,0);
        for(int i = 0; i < numCourses;i++){
            vector<int> pathVisited(numCourses,0);
            if(!vis[i]){
                if(isCycle(i,vis,adj,pathVisited)){return false;}
            }
        }
        return true;
    }

    bool isCycle(int node,vector<int>& vis,vector<vector<int>>& adj,vector<int>& pathVisited){
        vis[node] = 1;
        pathVisited[node] = 1;
        for(auto nei:adj[node]){
            if(!vis[nei]){
                if(isCycle(nei,vis,adj,pathVisited))return true;
            }else if(pathVisited[nei] && vis[nei]){return true;}
        }
        pathVisited[node] = 0;
        return false;
    }
};
