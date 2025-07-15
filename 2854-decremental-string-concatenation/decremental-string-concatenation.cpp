class Solution {
public:
    int solve(char s, char e, int i, vector<string>& words, vector<vector<vector<int>>>& dp) {
        if (i >= words.size()) return 0;

        if (dp[s - 'a'][e - 'a'][i] != -1) return dp[s - 'a'][e - 'a'][i];

        char f = words[i][0];
        char l = words[i].back();
        int len = words[i].length();

        
        int a = solve(s, l, i + 1, words, dp) + len - (e == f ? 1 : 0);

        
        int b = solve(f, e, i + 1, words, dp) + len - (l == s ? 1 : 0);

        return dp[s - 'a'][e - 'a'][i] = min(a, b);
    }

    int minimizeConcatenatedLength(vector<string>& words) {
        int n = words.size();
        string prev = words[0];

        
        vector<vector<vector<int>>> dp(26, vector<vector<int>>(26, vector<int>(n, -1)));

        return prev.size() + solve(prev[0], prev.back(), 1, words, dp);
    }
};
