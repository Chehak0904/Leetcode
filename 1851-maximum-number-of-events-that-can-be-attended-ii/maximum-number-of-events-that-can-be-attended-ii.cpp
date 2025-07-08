class Solution {
public:
    int f(int i, int k, vector<vector<int>>& e, vector<vector<int>>& t) {
        if (i >= e.size() || k <= 0) return 0;
        if (t[i][k] != -1) return t[i][k];

        
        int lo = i + 1, hi = e.size() - 1;
        int nextIdx = e.size();  

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (e[mid][0] > e[i][1]) {
                nextIdx = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        int take = e[i][2] + f(nextIdx, k - 1, e, t);
        int not_take = f(i + 1, k, e, t);

        return t[i][k] = max(take, not_take);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end()); 
        int n = events.size();
        vector<vector<int>> t(n, vector<int>(k + 1, -1));
        return f(0, k, events, t);
    }
};
