class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<int, pair<int, int>>> q;
        vector<int> dirX = {0, 0, -1, 1};
        vector<int> dirY = {1, -1, 0, 0};
        
        q.push({entrance[0], {entrance[1], 0}});
        maze[entrance[0]][entrance[1]] = '+';  
        
        while (!q.empty()) {
            auto it = q.front(); q.pop();
            int i = it.first;
            int j = it.second.first;
            int steps = it.second.second;
            
            
            if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) &&
                !(i == entrance[0] && j == entrance[1])) {
                return steps;
            }
            
            for (int k = 0; k < 4; k++) {
                int n_i = i + dirX[k];
                int n_j = j + dirY[k];
                
                if (n_i >= 0 && n_i < m && n_j >= 0 && n_j < n &&
                    maze[n_i][n_j] == '.') {
                    q.push({n_i, {n_j, steps + 1}});
                    maze[n_i][n_j] = '+';  
                }
            }
        }
        return -1;
    }
};
