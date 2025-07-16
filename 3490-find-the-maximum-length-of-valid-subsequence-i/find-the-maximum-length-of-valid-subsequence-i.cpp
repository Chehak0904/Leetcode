class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odd = 0;
        int even = 0;
        int len = 1;
        int p = 0;  

        if (nums[0] % 2 == 0) {
            even++;
            p = 0;   
        } else {
            odd++;
            p = 1;   
        }

        for (int i = 1; i < nums.size(); i++) {
            int lp = 0;  

            if (nums[i] % 2 == 0) {
                even++;
                lp = 0;
            } else {
                odd++;
                lp = 1;
            }

            if (lp != p) {
                len++;    
                p = lp;    
            }
        }

        return max({even, odd, len});
    }
};
