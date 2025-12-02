class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>temp(n,0);
        for(int i=0;i<n;i++){
            int n_i=(i+k)%n;
            temp[n_i]=nums[i];
        }
        nums=temp;
    }
};