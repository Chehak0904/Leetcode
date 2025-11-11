class Solution {
public:
    int solve(int idx, vector<string>& strs, vector<int>& z, vector<int>& o,
              int m, int n, vector<vector<vector<int>>>& dp) {
        if (idx == strs.size())
            return 0;
        if (dp[idx][m][n] != -1)
            return dp[idx][m][n];

        int take = 0;
        if (m >= z[idx] && n >= o[idx]) {
            take = 1 + solve(idx + 1, strs, z, o, m - z[idx], n - o[idx], dp);
        }

        int not_take = solve(idx + 1, strs, z, o, m, n, dp);
        return dp[idx][m][n] = max(take, not_take);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int s = strs.size();
        vector<int> z, o;

        for (string t : strs) {
            int cntZ = 0, cntO = 0;
            for (char ch : t) {
                if (ch == '0')
                    cntZ++;
                else
                    cntO++;
            }
            z.push_back(cntZ);
            o.push_back(cntO);
        }

        vector<vector<vector<int>>> dp(
            s, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

        return solve(0, strs, z, o, m, n, dp);
    }
};
