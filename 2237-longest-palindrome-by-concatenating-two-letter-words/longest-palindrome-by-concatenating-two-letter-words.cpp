class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp1;
        unordered_map<string, int> mp2;
        int len = 0;

        for (auto w : words) {
            string rev = w;
            reverse(rev.begin(), rev.end());

            if (w == rev) {
                mp2[w]++;
            } else {
                if (mp1.find(rev) != mp1.end() && mp1[rev] > 0) {
                    len += 4;
                    mp1[rev]--;
                    if (mp1[rev] == 0) {
                        mp1.erase(rev);
                    }
                } else {
                    mp1[w]++;
                }
            }
        }

        int full = 0;
        bool cen = false;

        for (auto it : mp2) {
            if (it.second % 2 != 0) cen = true;
            full += it.second / 2;
        }

        len += full * 4;
        if (cen) len += 2;

        return len;
    }
};
