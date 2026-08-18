class Solution {
public:
    vector<vector<int>> dp;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        dp.resize(m,vector<int>(n,-1));
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                ans = max(ans,1+dfs(i,j,matrix));
            }
        }
        return ans;
    }
    
    int dfs(int r,int c,vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();

        if(dp[r][c] != -1)return dp[r][c];
        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,-1,1};

        int ans = 0;
        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nc < 0 || nr >= m || nc >= n || matrix[nr][nc] <= matrix[r][c])continue;
            ans = max(ans,1 + dfs(nr,nc,matrix));
        }
        return dp[r][c] = ans;
    }
};
