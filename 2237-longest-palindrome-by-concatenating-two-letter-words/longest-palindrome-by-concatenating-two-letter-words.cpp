class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n=words.size();
        unordered_map<string,int> mp;
        int len=0;
        //all equal pairs will also be handled here
        for(int i=0;i<n;i++){
            string rev= string() +words[i][1]+words[i][0];
            if(mp[rev]>0){
                len+=4;
                mp[rev]--;
            }
            else{
                mp[words[i]]++;
            }
        }
        //just handle central part here
        for(auto &it:mp){
            if(it.first[0]==it.first[1] && it.second>0){
                len+=2;
                break;
            }
        }
        return len;
    }
};