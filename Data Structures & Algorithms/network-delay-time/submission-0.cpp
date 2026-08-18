class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int> visited(n+1,0);
        for(auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        pq.push({0,k});
        int ans = 0;
        while(!pq.empty()){
            auto[time,node] = pq.top();
            pq.pop();
            if(visited[node])continue;
            visited[node] = 1;

            for(auto [nei,t]:adj[node]){
                if(!visited[nei]){
                    pq.push({t+time,nei});
                }
            }
            ans = max(ans,time);
        }

        for(int i = 1; i < n+1;i++ ){
            if(!visited[i])return -1;
        }
        return ans;
    }
};
