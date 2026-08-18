class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        queue<pair<int,int>> q;

        // Put all treasures into the queue
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        // Multi-source BFS
        while(!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {

                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr < 0 || nc < 0 ||
                   nr >= m || nc >= n ||
                   grid[nr][nc] != 2147483647) {
                    continue;
                }

                grid[nr][nc] = grid[r][c] + 1;

                q.push({nr, nc});
            }
        }
    }
};