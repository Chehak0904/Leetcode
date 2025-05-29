class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& triangle, int n) {
        if (i == n - 1) {
            return triangle[i][j];
        }
        if (dp[i][j] != -1) return dp[i][j];

        int d1 = solve(i + 1, j, dp, triangle, n);
        int d2 = solve(i + 1, j + 1, dp, triangle, n);
        
        return dp[i][j] = triangle[i][j] + min(d1, d2);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, 0, dp, triangle, n);
    }
};
