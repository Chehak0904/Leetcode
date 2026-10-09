class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        string ns = "";

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                ns += s[i];
            }
            else if (s[i] == ')') {
                if (i + 1 < n && s[i + 1] == ')') {
                    ns += '2';
                    i++;
                }
                else {
                    ns += '1';
                }
            }
        }

        int ans = 0;
        string stk = "";

        for (char ch : ns) {
            if (ch == '(') {
                stk += ch;
            }
            else if (ch == '1' && !stk.empty()) {
                ans += 1;
                stk.pop_back();
            }
            else if (ch == '1' && stk.empty()) {
                ans += 2;
            }
            else if (ch == '2' && stk.empty()) {
                ans += 1;
            }
            else if (ch == '2' && !stk.empty()) {
                stk.pop_back();
            }
        }

        while (!stk.empty()) {
            ans += 2;
            stk.pop_back();
        }

        return ans;
    }
};