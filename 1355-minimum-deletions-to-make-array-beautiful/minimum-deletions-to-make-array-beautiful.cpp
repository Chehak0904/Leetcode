class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int min_elements = 0; // to count deletions
        int idx = 0;          // last non-deleted element's index

        for (int i = 1; i < nums.size(); i++) {
            int corrected_idx = i - min_elements;
            
            if (corrected_idx % 2!= 0) { // we want nums[i] != nums[idx]
                if (nums[i] == nums[idx]) {
                    min_elements++; // delete nums[i]
                } else {
                    idx = i+1;
                }
            }
        }
         if ((nums.size() - min_elements) % 2 != 0) {
            min_elements++;
        }
        return min_elements;
    }
};
