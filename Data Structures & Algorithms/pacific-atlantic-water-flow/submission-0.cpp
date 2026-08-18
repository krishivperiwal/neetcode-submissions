class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> p(m,vector<int>(n,0));
        vector<vector<int>> a(m,vector<int>(n,0));

        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++){
            p[m-1][i] = 1;
            q.push({m-1,i});
        }
        for(int i = 0; i < m; i++){
            p[i][n-1] = 1;
            q.push({i,n-1});
        }

        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,-1,1};
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < 0 || nc < 0 || nr >= m || nc >= n || heights[nr][nc] < heights[r][c] || p[nr][nc])continue;

                p[nr][nc] = 1;
                q.push({nr,nc});
            }

        }

        for(int i = 0; i < n; i++){
            a[0][i] = 1;
            q.push({0,i});
        }
        for(int i = 0; i < m; i++){
            a[i][0] = 1;
            q.push({i,0});
        }

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < 0 || nc < 0 || nr >= m || nc >= n || heights[nr][nc] < heights[r][c] || a[nr][nc])continue;

                a[nr][nc] = 1;
                q.push({nr,nc});
            }

        }

        vector<vector<int>>ans;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j]&&p[i][j])ans.push_back({i,j});
            }
        }

        return ans;
    }  
};
