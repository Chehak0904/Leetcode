class Solution {
public:
    int minDiff = INT_MAX;
    vector<int> bestSplit;
    void solve(vector<int>& d, int n, int k, vector<int>& temp) {
        if (k == 0 && n == 1) {
            int maxi = *max_element(temp.begin(), temp.end());
            int mini = *min_element(temp.begin(), temp.end());
            if ((maxi - mini) < minDiff) {
                minDiff = maxi - mini;
                bestSplit = temp;
            }
        }
        if (k <= 0) return;
        for (int i : d) {
            if (n % i == 0) {
                temp.push_back(i);
                solve(d, n / i, k - 1, temp);
                temp.pop_back();
            }
        }
    }
    vector<int> minDifference(int n, int k) {
        vector<int> divisors;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0)
                divisors.push_back(i);
        }
        vector<int> temp;
        solve(divisors, n, k, temp);
        if (bestSplit.empty())
            return {-1};
        else
            return bestSplit;
    }
};