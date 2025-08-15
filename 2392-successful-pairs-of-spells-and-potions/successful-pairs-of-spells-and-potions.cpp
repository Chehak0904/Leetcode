class Solution {
public:
    int binary_search(vector<int>& nums, long long target) {
        int n=nums.size();
        int i = 0 , j = n- 1;
        int ans = -1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (nums[mid] >= target) {
                ans = mid;
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return (ans==-1)?0:n-ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,long long success) {
        vector<int> ans;
        sort(potions.begin(), potions.end());
        for (auto num:spells) {
            long long target = -1;
            if (success % num == 0)target = success / num;
            else target = (success / num) + 1;
            int a = binary_search(potions, target);
            ans.push_back(a);
        }
        return ans;
    }
};