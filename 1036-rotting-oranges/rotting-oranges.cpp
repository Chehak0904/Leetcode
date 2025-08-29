class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) return 0; 

        int time = -1;
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        while (!q.empty()) {
            int sz = q.size();
            time++; 
            for (int i = 0; i < sz; i++) {
                auto [x, y] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int n_i = x + dx[k];
                    int n_j = y + dy[k];
                    if (n_i >= 0 && n_j >= 0 && n_i < grid.size() &&
                        n_j < grid[0].size() && grid[n_i][n_j] == 1) {
                        fresh--;
                        grid[n_i][n_j] = 2;
                        q.push({n_i, n_j});
                    }
                }
            }
        }

        return fresh == 0 ? time : -1;
    }
};
