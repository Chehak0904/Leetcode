class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long total_sum = accumulate(nums.begin(), nums.end(), 0);
        long long sum = total_sum - x;
        int i = 0;
        int j = 0;
        long long curr_sum = 0;
        int ans = INT_MIN;
        while (j < nums.size()) {
            curr_sum += nums[j];
            while (i<=j && curr_sum > sum) {
                curr_sum -= nums[i];
                i++;
            }
            if (curr_sum == sum) {
                ans = max(ans, j - i + 1);
            }
            j++;
        }
        if (ans == INT_MIN)
            return -1;
        return nums.size()-ans;
    }
};