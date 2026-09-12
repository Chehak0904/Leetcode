class Solution {
public:

    int binarySearch(vector<vector<int>>& events, int target) {
        int n = events.size();

        int low = 0;
        int high = n - 1;
        int ans = n;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(events[mid][0] >= target) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }

    int maxTwoEvents(vector<vector<int>>& events) {

        int n = events.size();

        sort(events.begin(), events.end());

        vector<int> max_val(n);

        max_val[n-1] = events[n-1][2];

        for(int i = n-2; i >= 0; i--) {
            max_val[i] = max(max_val[i+1], events[i][2]);
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {

            int end1 = events[i][1];

            int j = binarySearch(events, end1 + 1);

            ans = max(ans, events[i][2]);

            if(j < n) {
                ans = max(ans, events[i][2] + max_val[j]);
            }
        }

        return ans;
    }
};