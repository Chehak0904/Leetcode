class Solution {
public:
    
    int find_ans(vector<pair<int,int>>& diff, int target) {
        int ans = -1;
        int i = 0, j = diff.size() - 1;
        while (i <= j) {
            int m = (i + j) / 2;
            if (diff[m].first <= target) {
                ans = m;
                i = m + 1;
            } else {
                j = m - 1;
            }
        }
        return ans;
    }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> vec;
        for (int i = 0; i < difficulty.size(); i++) {
            vec.push_back({difficulty[i], profit[i]});
        }

        
        sort(vec.begin(), vec.end());

        
        vector<int> max_profit(difficulty.size());
        max_profit[0] = vec[0].second;
        for (int i = 1; i < vec.size(); i++) {
            max_profit[i] = max(max_profit[i - 1], vec[i].second);
        }

        int ans = 0;
        for (int i = 0; i < worker.size(); i++) {
            int idx = find_ans(vec, worker[i]);
            if (idx != -1) {
                ans += max_profit[idx];
            }
        }

        return ans;
    }
};
