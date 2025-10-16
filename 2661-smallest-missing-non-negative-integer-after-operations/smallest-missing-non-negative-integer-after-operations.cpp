class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> vec(value, 0); 
        for (int i = 0; i < nums.size(); i++) {
            int r = ((nums[i] % value) + value) % value; 
            vec[r]++;
        }

        int temp = 0;
        while (true) {
            int r = temp % value;
            if (vec[r] == 0) break; 
            vec[r]--;               
            temp++;                 
        }
        return temp;
    }
};
