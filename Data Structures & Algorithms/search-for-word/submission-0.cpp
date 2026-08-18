class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(word[0] == board[i][j]){
                    char ch = board[i][j] ;
                    board[i][j] = '.';
                    if(find(1,i,j,board,word))return true;
                    board[i][j] = ch;
                }
            }
        }
        return false;
    }

    bool find(int index,int r, int c,vector<vector<char>>& board,string word){
        if(index == word.size()){return true;}
        int m = board.size();
        int n = board[0].size();
        
        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,-1,1};

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nc < 0 || nr >= m || nc >= n || board[nr][nc] != word[index])continue;
            char ch = board[nr][nc] ;
            board[nr][nc] = '.';
            if(find(index+1,nr,nc,board,word))return true;
            board[nr][nc] = ch;
        }

        return false;
    }
};
