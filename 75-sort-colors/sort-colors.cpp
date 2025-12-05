class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;

        while (i < n && nums[i] == 0) i++;
        while (j >= 0 && nums[j] == 2) j--;

        int k = i;

        while (i<j && k <=j) {

            if (nums[k] == 0) {
                swap(nums[k], nums[i]);
                k++;
                i++;
            }
            else if (nums[k] == 2) {
                swap(nums[k], nums[j]);
                j--;
            }
            else {
                k++;
            }
        }
    }
};
