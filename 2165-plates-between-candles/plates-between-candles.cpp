class Solution {
public:
    int leftmost(vector<int>& candles, int l) {
        int i = 0, j = candles.size() - 1, ans = -1;
        while (i <= j) {
            int m = i + (j - i) / 2;
            if (candles[m] >= l) {
                ans = m;
                j = m - 1;
            } else {
                i = m + 1;
            }
        }
        return ans;
    }
    int rightmost(vector<int>& candles, int r) {
        int i = 0, j = candles.size() - 1, ans = -1;
        while (i <= j) {
            int m = i + (j - i) / 2;
            if (candles[m] <= r) {
                ans = m;
                i = m + 1;
            } else {
                j = m - 1;
            }
        }
        return ans;
    }

    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> prefix(n, 0);
        vector<int> candles;
        vector<int> ans;

        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '|') candles.push_back(i);
            prefix[i] = sum + (s[i] == '*' ? 1 : 0);
            sum = prefix[i];
        }

        for (auto &q : queries) {
            int lf = q[0], rf = q[1];
            int li = leftmost(candles, lf);
            int ri = rightmost(candles, rf);

            if (li == -1 || ri == -1 || li > ri) {
                ans.push_back(0);
                continue;
            }

            int leftIdx = candles[li], rightIdx = candles[ri];
            int total = prefix[rightIdx] - prefix[leftIdx];
            ans.push_back(total);
        }

        return ans;
    }
};
