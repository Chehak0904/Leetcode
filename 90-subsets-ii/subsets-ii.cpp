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

        
        i++;
        while (i < nums.size() && nums[i] == nums[i - 1]) {
            i++;
        }
        f(i, temp, ans, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  
        vector<vector<int>> ans;
        vector<int> temp;
        f(0, temp, ans, nums);
        return ans;
    }
};
