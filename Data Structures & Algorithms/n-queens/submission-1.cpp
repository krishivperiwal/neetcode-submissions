class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        dfs(0,board,n);
        return ans;
    }

    void dfs(int row,vector<string>& board,int n){
        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int c = 0; c < n;c++){
            if(check(row,c,board)){
                board[row][c] = 'Q';
                dfs(row + 1,board,n);
                board[row][c] = '.';
            }
        }
    }

    bool check(int r,int c,vector<string> temp){
        int n = temp.size();
        for(int i = 0; i < n; i++){
            if(temp[i][c] == 'Q')return false;
        }

        int dr[4] = {1,1,-1,-1};
        int dc[4] = {1,-1,-1,1};

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            while(nr >= 0 && nc >= 0 && nr < n && nc < n){
                if(temp[nr][nc] == 'Q')return false;
                nr += dr[i];
                nc += dc[i];
            }
        }
        return true;
    }   
};
