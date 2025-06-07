class Solution {
public:
    int find_interval(vector<vector<int>>& temp, unordered_map<int, int>& mp, int target) {
        int i = 0;
        int j = temp.size() - 1;
        int ans = -1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (temp[mid][0] >= target) {
                ans = mid;
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        if (ans == -1) return -1;
        return mp[temp[ans][0]];
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> ans(n);

        unordered_map<int, int> mp; 
        vector<vector<int>> temp = intervals;

        for (int i = 0; i < n; i++) {
            mp[intervals[i][0]] = i;
        }

        sort(temp.begin(), temp.end()); 

        for (int i = 0; i < n; i++) {
            int target = intervals[i][1];
            ans[i] = find_interval(temp, mp, target);
        }

        return ans;
    }
};
