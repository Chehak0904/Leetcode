class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int r, int c, char ch) {
        for (int i = 0; i < board.size(); i++) {
            if (board[i][c] == ch) return false;
            if (board[r][i] == ch) return false;
            if (board[3 * (r / 3) + (i / 3)][3 * (c / 3) + (i % 3)] == ch) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isSafe(board, i, j, ch)) {
                            board[i][j] = ch;
                            if (solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false; 
                }
            }
        }
        return true; 
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};