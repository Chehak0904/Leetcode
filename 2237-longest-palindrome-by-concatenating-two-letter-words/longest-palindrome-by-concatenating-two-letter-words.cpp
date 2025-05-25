class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int len = 0;

        for (auto w : words) {
            string rev = w;
            reverse(rev.begin(), rev.end());

            if (w == rev) {
                mp[w]++;
            } else {
                if (mp.find(rev) != mp.end() && mp[rev] > 0) {
                    len += 4;
                    mp[rev]--;
                    if (mp[rev] == 0) {
                        mp.erase(rev);
                    }
                } else {
                    mp[w]++;
                }
            }
        }

        int full = 0;
        bool cen = false;

        for (auto it : mp) {
            string s = it.first;
            if (s[0] == s[1]) {
                if (it.second % 2 != 0)
                    cen = true;
                full += it.second / 2;
            }
        }

        len += full * 4;
        if (cen)
            len += 2;

        return len;
    }
};
