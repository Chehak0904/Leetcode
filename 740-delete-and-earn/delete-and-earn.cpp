class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        vector<int> temp;
        for (auto it : mp) {
            temp.push_back(it.first);
        }

        sort(temp.begin(), temp.end()); 

        int m = temp.size();
        if (m == 0) return 0;
        if (m == 1) return temp[0] * mp[temp[0]];

        vector<int> dp(m, 0);
        dp[0] = temp[0] * mp[temp[0]];

        if (temp[1] == temp[0] + 1) {
            dp[1] = max(dp[0], temp[1] * mp[temp[1]]);
        } else {
            dp[1] = dp[0] + temp[1] * mp[temp[1]];
        }

        for (int i = 2; i < m; i++) {
            if (temp[i] == temp[i - 1] + 1) {
                dp[i] = max(dp[i - 1], dp[i - 2] + temp[i] * mp[temp[i]]);
            } else {
                dp[i] = dp[i - 1] + temp[i] * mp[temp[i]];
            }
        }

        return dp[m - 1];
    }
};
