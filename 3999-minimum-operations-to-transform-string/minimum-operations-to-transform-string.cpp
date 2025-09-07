class Solution {
public:
    int minOperations(string s) {
        map<char, int> st;
        for (int i = 0; i < s.length(); i++) {
            st[s[i]]++;
        }
        string temp = "";
        for (auto it : st) {
            temp.push_back(it.first);
        }
        int ans = 0;
        for (int i = 0; i < temp.size() - 1; i++) {
            if (temp[i] != 'a') {
                ans += (temp[i + 1] - temp[i]);
            }
        }
        ans += (26 - (temp.back() - 'a')) % 26;
        return ans;
    }
};