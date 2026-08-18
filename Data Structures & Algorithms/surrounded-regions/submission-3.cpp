class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,-1));

        queue<pair<int,int>> q;

        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O'){
            q.push({i,0});
            vis[i][0] = 1;}
            if(board[i][n-1] == 'O'){
            q.push({i,n-1});
            vis[i][n-1] = 1;}
        } 

        for(int i = 0; i < n; i++){
            if(board[0][i] == 'O'){
                q.push({0,i});
                vis[0][i] = 1;
            }
            if(board[m-1][i] == 'O'){
                q.push({m-1,i});
                vis[m-1][i] = 1;
            }
        } 

        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,-1,1};

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr < 0 || nc < 0 || nr >= m || nc >= n || board[nr][nc] == 'X' || vis[nr][nc] == 1)continue;

                vis[nr][nc] = 1;
                q.push({nr,nc});
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O' && vis[i][j] != 1){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
