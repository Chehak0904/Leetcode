class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);
        int i = 0;
        int j = n - 1;
        int st = n;
         while (i <= j) {
            if (i == j) {
                ans[i] = 0;
            } else {
                ans[i] = st;
                ans[j] = -1 * st;
                st--;
            }
            i++;
            j--;
        }
        return ans;
    }
};