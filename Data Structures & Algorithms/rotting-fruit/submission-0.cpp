class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int num = 0;
        int ans = 0;
        queue<pair<int,pair<int,int>>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1)num++;
                else if(grid[i][j] == 2)q.push({0,{i,j}});
            }
        }

        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,-1,1};

        
        while(!q.empty()){
            auto [t,pos] = q.front();
            auto [r,c] = pos;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr < 0 || nc < 0 || nr >= m || nc >=n || grid[nr][nc] !=1)continue;
                ans = max(ans,1 + t);
                grid[nr][nc] = 2;
                q.push({1+t,{nr,nc}});
                num--;
            }
        }

        return num != 0?-1:ans;
    }
};
