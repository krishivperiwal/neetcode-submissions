class Solution {
public:
    vector<int> ans;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        for(int i = 0; i < numCourses; i++){
            vector<int> pathVisited(numCourses,0);
            if(!visited[i]){
                if(isCycle(i,pathVisited,adj,visited)){
                    return {};
                }
            }
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }

    bool isCycle(int node,vector<int>& pathVisited,vector<vector<int>>& adj,vector<int>& visited){
        visited[node] = 1;
        pathVisited[node] = 1;

        for(auto nei:adj[node]){
            if(!visited[nei]){
                if(isCycle(nei,pathVisited,adj,visited))return true;
            }else if(pathVisited[nei] && visited[nei])return true;   
        }

        pathVisited[node] = 0;
        ans.push_back(node);
        return false;
    }
};
