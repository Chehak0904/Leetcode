class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();
        if(n%2) return {};
        unordered_map<int,int>mp;
        sort(changed.begin(),changed.end());
        vector<int>ans;
         for(auto &num:changed){
            if(num%2==0 && mp.count(num/2)){
               ans.push_back(num/2);
               mp[num/2]--;
               if(mp[num/2]==0) mp.erase(num/2);
            }
            else{
                mp[num]++;
            }
         }
         return (ans.size()==n/2)?ans:vector<int>{};
        

        
    }
};