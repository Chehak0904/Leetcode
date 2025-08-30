class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,unordered_set<int>>row;
        unordered_map<char,unordered_set<int>>col;
        unordered_map<char,unordered_set<int>>sqr;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char ele=board[i][j];
                if(ele=='.') continue;
                int r=i;
                int c=j;
                int s=(i/3)*3+(j/3);
                if(row[r].find(ele)==row[r].end()) row[r].insert(ele);
                else return false;
                if(col[c].find(ele)==col[c].end()) col[c].insert(ele);
                else return false;
                if(sqr[s].find(ele)==sqr[s].end()) sqr[s].insert(ele);
                else return false;
            }
        }
        return true;

    }
};