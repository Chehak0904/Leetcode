class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //comparator function
        sort(nums.begin(),nums.end(),[](int &a,int &b){
            return a>b;
        });
        return nums[k-1];
        
    }
};