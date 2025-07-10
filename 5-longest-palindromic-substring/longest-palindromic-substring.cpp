class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int st = -1;
        int maxLen = -1;
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
            int len = 1;
            if (len > maxLen) {
                st = i;
                maxLen = 1;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                int len = 2;
                if (len > maxLen) {
                    st = i;
                    maxLen = 2;
                }
            }
        }
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                    dp[i][j] = 1;
                    int l = len;
                    if (l > maxLen) {
                        st = i;
                        maxLen = l;
                    }
                }
            }
        }
        return s.substr(st, maxLen);
    }
};