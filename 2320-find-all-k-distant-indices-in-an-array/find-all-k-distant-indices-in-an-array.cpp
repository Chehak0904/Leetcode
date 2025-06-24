class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>key_indx;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==key){
                key_indx.push_back(i);
            }
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<key_indx.size();j++){
                if(abs(i-key_indx[j])<=k){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
        
    }
};