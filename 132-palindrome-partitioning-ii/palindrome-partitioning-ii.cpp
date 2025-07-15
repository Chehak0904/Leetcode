class Solution {
public:
    bool isPalindrome(int i, int j, string& s,vector<vector<int>>&dp) {
        if(dp[i][j]!=-1) return dp[i][j];
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return dp[i][j]=true;
    }
    int f(int i, int j, string& s, vector<int>& dp1,vector<vector<int>>&dp2) {
        if(i==j) return 0;
        if (dp1[i] != -1)
            return dp1[i];
        if (isPalindrome(i, j, s,dp2))
            return 0;
        int ans = INT_MAX;
        for (int k = i; k < j; k++) {
            if (isPalindrome(i, k, s,dp2)) {
                ans = min(ans, 1 + f(k + 1, j, s, dp1,dp2));
            }
        }
        return dp1[i] = ans;
    }
    int minCut(string s) {
        int n = s.length();
        vector<int>dp1(n,-1);
        vector<vector<int>> dp2(n, vector<int>(n, -1));
        return f(0, n-1, s, dp1,dp2);
    }
};