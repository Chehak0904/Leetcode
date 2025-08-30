class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row(9), col(9),sqr(9);
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char ele = board[i][j];
                if (ele == '.') continue;

                int s = (i / 3) * 3 + (j / 3);  

                if (row[i].count(ele) || col[j].count(ele) || sqr[s].count(ele))
                    return false;

                row[i].insert(ele);
                col[j].insert(ele);
                sqr[s].insert(ele);
            }
        }
        return true;
    }
};
