class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int n = s.length();
        int ans = 0;
        int i = n - 1;

        while (i >= 0) {
            if (i > 0 && s[i] == 'V' && s[i - 1] == 'I') {
                ans += 4;
                i -= 2;
            }
            else if (i > 0 && s[i] == 'X' && s[i - 1] == 'I') {
                ans += 9;
                i -= 2;
            }
            else if (i > 0 && s[i] == 'L' && s[i - 1] == 'X') {
                ans += 40;
                i -= 2;
            }
            else if (i > 0 && s[i] == 'C' && s[i - 1] == 'X') {
                ans += 90;
                i -= 2;
            }
            else if (i > 0 && s[i] == 'D' && s[i - 1] == 'C') {
                ans += 400;
                i -= 2;
            }
            else if (i > 0 && s[i] == 'M' && s[i - 1] == 'C') {
                ans += 900;
                i -= 2;
            }
            else {
                ans += mp[s[i]];
                i--;
            }
        }

        return ans;
    }
};
