class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n+1);
        int left = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                cnt++;
        }
       
        int maxi = 0;
        for (int i = 0; i < n; i++) {

            temp[i] = left + cnt;
            if (nums[i] == 0)
                left++;
            if (nums[i] == 1)
                cnt--;
            maxi = max(maxi, temp[i]);
        }
        temp[n]=left;
        maxi=max(maxi,temp[n]);
        vector<int> ans;
        for (int i = 0; i < n+1; i++) {
            if (temp[i] == maxi)
                ans.push_back(i);
        }
        return ans;
    }
};