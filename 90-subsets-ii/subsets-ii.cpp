class Solution {
public:
    void f(int i, vector<int>& temp, vector<vector<int>>& ans, vector<int>& nums) {
        if (i == nums.size()) {
            ans.push_back(temp);
            return;
        }

        
        temp.push_back(nums[i]);
        f(i + 1, temp, ans, nums);
        temp.pop_back();

        
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }

       
        f(i + 1, temp, ans, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        f(0, temp, res, nums);
        return res;
    }
};
