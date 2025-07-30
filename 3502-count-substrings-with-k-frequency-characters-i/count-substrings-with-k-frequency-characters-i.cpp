class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        unordered_map<char, int> mp;
        bool flag = false;
        int ans = 0;
        int i = 0, j = 0;
        int n = s.length();

        while (j < n) {
            mp[s[j]]++;
            if (mp[s[j]] == k) flag = true;
            while (flag) {
                ans += n - j;
                mp[s[i]]--;
                if (mp[s[i]] == k - 1) {
                    flag = false;
                }
                i++;
            }

            j++;
        }

        return ans;
    }
};
