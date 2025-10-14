class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if (k == 1) return true;

        vector<pair<int,int>> vec;
        int start = 0;
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                continue;
            } else {
                int len = i - start + 1;  
                if (len >= k) {
                    if (len >= 2 * k) return true; 
                    vec.push_back({start, i});
                }
                start = i + 1;  
            }
        }

        
        int len = n - start;
        if (len >= k) {
            if (len >= 2 * k) return true;
            vec.push_back({start, n - 1});
        }

        
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i].first == vec[i - 1].second + 1) {
                return true;
            }
        }

        return false;
    }
};
