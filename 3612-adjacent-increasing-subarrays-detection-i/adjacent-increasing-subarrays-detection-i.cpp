class Solution {
public:
    bool check(int i, int k, vector<int>& nums) {
        if (i + k > nums.size()) return false;
        for (int j = i + 1; j < i + k; j++) {
            if (nums[j] <= nums[j - 1]) return false;
        }
        return true;
    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i <n-k; i++) {
            bool flag = true;
            for (int j = i + 1; j < i + k; j++) {
                if (nums[j] <= nums[j - 1]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                if (check(i + k, k, nums))
                    return true;
            }
        }

        return false;
    }
};
