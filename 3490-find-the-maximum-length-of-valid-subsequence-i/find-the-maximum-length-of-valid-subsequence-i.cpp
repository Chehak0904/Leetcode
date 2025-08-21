class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odd = 0;
        int even = 0;
        int s = -1;
        int alt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                even++;
                if (s == -1) {
                    s = 1;
                    alt++;
                } else if (s == 0) {
                    alt++;
                    s = 1;
                }
            } else {
                odd++;
                if (s == -1) {
                    alt++;
                    s = 0;
                } else if (s == 1) {
                    alt++;
                    s = 0;
                }
            }
        }
        return max({even, odd, alt});
    }
};