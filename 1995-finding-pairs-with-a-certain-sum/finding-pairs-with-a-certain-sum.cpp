class FindSumPairs {
public:
    vector<int>v2;
    unordered_map<int,int>mp1;
    unordered_map<int,int>mp2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v2=nums2;
        for(int i=0;i<nums1.size();i++){
            mp1[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            mp2[nums2[i]]++;
        }
        
        
    }
    
    void add(int index, int val) {
        int oldVal=v2[index];
        v2[index]+=val;
        mp2[v2[index]]++;
        mp2[oldVal]--;
        if(mp2[oldVal]==0) mp2.erase(mp2[oldVal]);
        
    }
    
    int count(int tot) {
        int cnt=0;
        for(auto &[num,freq]:mp1){
            int target=tot-num;
            if(mp2.find(target)!=mp2.end()){
                cnt+=freq*mp2[target];

            }
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */