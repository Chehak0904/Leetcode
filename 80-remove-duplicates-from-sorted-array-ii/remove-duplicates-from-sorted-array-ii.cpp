class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n; 

        int k = 1, cnt = 1;
        int i = 1;
        while (i < n) {
            if (nums[i] == nums[i - 1]) {
                cnt++;
            } else {
                cnt = 1;
            }
            if (cnt <= 2) {
                nums[k] = nums[i]; 
                k++;
            }
            i++;
        }
        return k;
    }
};
