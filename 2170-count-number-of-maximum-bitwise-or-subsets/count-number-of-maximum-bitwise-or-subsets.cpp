class Solution {
public:
    void solve(int idx, vector<int>& nums, int curr, int maxi, int& count) {
        if (idx == nums.size()) {
            if (curr == maxi) count++;
            return;
        }

        solve(idx + 1, nums, curr | nums[idx], maxi, count);
        solve(idx + 1, nums, curr, maxi, count);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0;
        for (int num : nums) {
            maxi |= num;
        }

        int count = 0;
        solve(0, nums, 0, maxi, count);
        return count;
    }
};
