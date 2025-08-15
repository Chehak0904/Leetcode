class Solution {
public:
    bool possible(vector<int>& time, long long totalTime, long long totalTrips) {
        long long cnt = 0;
        for (int t : time) {
            cnt += totalTime / t; 
            if (cnt >= totalTrips) return true; 
        }
        return cnt >= totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1;
        long long r = 1LL * (*min_element(time.begin(), time.end())) * totalTrips;
        long long ans = -1;

        while (l <= r) {
            long long mid = (l + r) / 2;
            if (possible(time, mid, totalTrips)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
