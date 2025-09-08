class Solution {
public:
    bool func(int idx, string &s, unordered_set<string>& st,vector<int>&dp) {
        if (idx >= s.length()) return true;
        if(dp[idx]!=-1) return dp[idx];
        for (int i = 1; i <= s.length() - idx; i++) {
            string sub = s.substr(idx, i);
            if (st.find(sub) != st.end() && func(idx + i, s, st,dp)) {
                return dp[idx]=true;
            }
        }
        return dp[idx]=false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for (int i = 0; i < wordDict.size(); i++) {
            st.insert(wordDict[i]);
        }
        vector<int>dp(s.length(),-1);
        return func(0, s, st,dp);
    }
};
