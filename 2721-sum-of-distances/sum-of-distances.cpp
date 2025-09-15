class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        for (auto& [num, vec] : mp) {
            int l = vec.size();
            vector<long long> prefix(l, 0);
            prefix[0] = vec[0];
            for (int i = 1; i < l; i++) {
                prefix[i] = prefix[i - 1] + vec[i];
            }
            for (int i = 0; i < l; i++) {
                long long left = (long long)vec[i] * i - (i > 0 ? prefix[i - 1] : 0);
                long long right = (prefix[l - 1] - prefix[i]) - (long long)vec[i] * (l - i - 1);
                ans[vec[i]] = left + right;
            }
        }

        return ans;
    }
};
