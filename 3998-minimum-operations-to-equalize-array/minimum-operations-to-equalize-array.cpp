class Solution {
public:
    int minOperations(vector<int>& nums) {
        int num = nums[0];
        bool flag = true;
        for (int n : nums) {
            if (n != num) {
                flag = false;
                break;
            }
        }
        return (flag) ? 0 : 1;
    }
};