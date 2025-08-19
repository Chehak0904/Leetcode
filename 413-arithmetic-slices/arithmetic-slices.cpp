class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() <= 2)
            return 0;
        int cd = nums[1] - nums[0];
        int i = 0;
        int j = 2;
        int ans = 0;
        while (j < nums.size()) {
            int cd_ = nums[j] - nums[j - 1];
            if (cd_ == cd) {

                int len = j - i + 1;
                if (len >= 3) {
                    ans += len - 3 + 1;
                }
                j++;
            } else {

                i = j - 1;
                cd = cd_;
                j++;
            }
        }
        return ans;
    }
};