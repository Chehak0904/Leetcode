class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len=0;
        int i=0;
        int j=0;
        unordered_map<int,int>mp;
        while(j<s.length()){
            mp[s[j]]++;
            while(mp.size()<j-i+1){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
            max_len=max(max_len,j-i+1);
            j++;

        }
        return max_len;
        
    }
};