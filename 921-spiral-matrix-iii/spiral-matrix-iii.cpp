class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart) {
        vector<vector<int>> ans;
        int x = rStart;
        int y = cStart;
        int s = 0;
        ans.push_back({x, y});

        while (ans.size() < rows * cols) {
            s++;
            for (int i = 0; i < s; i++) {
                y = y + 1;
                if (x >= 0 && x < rows && y >= 0 && y < cols) {
                    ans.push_back({x, y});
                }
            }
            for (int i = 0; i < s; i++) {
                x = x + 1;
                if (x >= 0 && x < rows && y >= 0 && y < cols) {
                    ans.push_back({x, y});
                }
            }
            s++;
            for (int i = 0; i < s; i++) {
                y = y - 1;
                if (x >= 0 && x < rows && y >= 0 && y < cols) {
                    ans.push_back({x, y});
                }
            }
            for (int i = 0; i < s; i++) {
                x = x - 1;
                if (x >= 0 && x < rows && y >= 0 && y < cols) {
                    ans.push_back({x, y});
                }
            }
        }

        return ans;
    }
};