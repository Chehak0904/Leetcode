class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                dp[i][j] = (s1[i] == s2[j]) ? s1[i] + dp[i + 1][j + 1]
                                            : max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        int n1 = 0, n2 = 0;
        for (int i = 0; i < s1.length(); i++) {
            n1 += s1[i];
        }
        for (int i = 0; i < s2.length(); i++) {
            n2 += s2[i];
        }
        return n1 + n2 - (2 * dp[0][0]);
    }
};