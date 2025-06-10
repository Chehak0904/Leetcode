class Solution {
public:
    int maxDifference(string s) {
        //max freq of odd and min freq of even
        int n=s.length();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        int a1=0;
        int a2=n;
        for(auto it: mp){
            if(it.second%2==0){
                a2=min(a2,it.second);

            }
            else{
                a1=max(a1,it.second);

            }
        }
        return a1-a2;
    }
};