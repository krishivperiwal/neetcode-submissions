class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // Check rows
        for (int r = 0; r < 9; r++) {
            unordered_set<char> st;
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;

                if (board[r][c] < '1' || board[r][c] > '9' ||
                    st.contains(board[r][c]))
                    return false;

                st.insert(board[r][c]);
            }
        }

        // Check columns
        for (int c = 0; c < 9; c++) {
            unordered_set<char> st;
            for (int r = 0; r < 9; r++) {
                if (board[r][c] == '.') continue;

                if (board[r][c] < '1' || board[r][c] > '9' ||
                    st.contains(board[r][c]))
                    return false;

                st.insert(board[r][c]);
            }
        }

        // Check 3x3 boxes
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                unordered_set<char> st;

                for (int sr = i; sr < i + 3; sr++) {
                    for (int sc = j; sc < j + 3; sc++) {

                        if (board[sr][sc] == '.') continue;

                        if (board[sr][sc] < '1' || board[sr][sc] > '9' ||
                            st.contains(board[sr][sc]))
                            return false;

                        st.insert(board[sr][sc]);
                    }
                }
            }
        }

        return true;
    }
};