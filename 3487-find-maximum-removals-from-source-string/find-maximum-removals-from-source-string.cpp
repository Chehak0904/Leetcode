class Solution {
public:
    int solve(int i, int j, unordered_set<int>& s, string& src, string& pat,
              vector<vector<int>>& dp) {
        
        
        if (j == pat.length()) {
            int extraDeletes = 0;
            for (int k = i; k < src.length(); k++) {
                if (s.find(k) != s.end()) extraDeletes++;
            }
            return extraDeletes;
        }

        
        if (i == src.length()) return -1000000000;

        if (dp[i][j] != -1) return dp[i][j];
        
        int ans = -1000000000;
        
      
        if (s.find(i) != s.end()) {
            ans = max(ans, 1 + solve(i + 1, j, s, src, pat, dp));
        }
        
        
        if (src[i] == pat[j]) {
            ans = max(ans, solve(i + 1, j + 1, s, src, pat, dp));
        }
        
      
        ans = max(ans, solve(i + 1, j, s, src, pat, dp));
        
        return dp[i][j] = ans;
    }

    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        unordered_set<int> s;
        for (int idx : targetIndices) s.insert(idx);

        vector<vector<int>> dp(source.length(), vector<int>(pattern.length(), -1));

        int res = solve(0, 0, s, source, pattern, dp);
        return max(0, res); 
    }
};
