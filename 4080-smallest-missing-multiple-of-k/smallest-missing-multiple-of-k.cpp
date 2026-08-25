class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>s(nums.begin(),nums.end());
        int num=k;
        while(true){
            if(s.find(num)==s.end()){
                return num;
            }
            num=num+k;
        }
        return -1;
        
    }
};