class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1;
        int val = nums[0];
        int cnt = 1;
        int k=1;
        while (i < nums.size()) {
            if (nums[i] == nums[i - 1]) {
                i++;
            } else {
                val = nums[i];
                nums[k]=val;
                k++;
                i++;
                cnt++;
            }
        }
        return cnt;
    }
};