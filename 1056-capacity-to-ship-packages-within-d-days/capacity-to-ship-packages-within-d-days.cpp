class Solution {
public:
    bool check(vector<int>& weights, int days, int k) {
        int sum = 0;
        int day_count = 1; 
        for (int i = 0; i < weights.size(); i++) {
            if (sum + weights[i] <= k) {
                sum += weights[i];
            } else {
                sum = weights[i]; 
                day_count++;
            }
        }
        return day_count <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int total_weight = 0;
        int max_weight = 0;
        for (int i = 0; i < weights.size(); i++) {
            total_weight += weights[i];
            max_weight = max(max_weight, weights[i]);
        }

        int l = max_weight;       
        int r = total_weight;     

        while (l < r) {
            int mid = l + (r - l) / 2; 
            if (check(weights, days, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
};
