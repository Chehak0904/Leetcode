class Solution {
public:
    vector<vector<vector<int>>> dp;

    bool solve(int i, int j, int b, vector<vector<char>>& grid) {

        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return false;

        if(grid[i][j] == ')') {
            b++;
        }
        else {
            b--;

            if(b < 0)
                return false;
        }

        if(i == 0 && j == 0)
            return b == 0;

        if(dp[i][j][b] != -1)
            return dp[i][j][b];

        return dp[i][j][b] =
            solve(i-1, j, b, grid) ||
            solve(i, j-1, b, grid);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //i->0-n-1
        //j->->m-1;
        //b- m+n+1

        dp.assign(n, vector<vector<int>>(m, vector<int>(n + m, -1)));

        return solve(n-1, m-1, 0, grid);
    }
};