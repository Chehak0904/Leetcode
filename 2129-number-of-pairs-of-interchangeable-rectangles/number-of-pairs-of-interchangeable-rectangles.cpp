class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<string,long long>mp;
        long long cnt=0;
        for(vector<int>&v:rectangles){
            int a=v[0];
            int b=v[1];
            long long g=__gcd(a,b);
            a=a/g;
            b=b/g;
            string s=to_string(a)+"/"+to_string(b);
            if(mp.find(s)!=mp.end()){
                cnt+=mp[s];
            }
            mp[s]++;
        }
        return cnt;
        
    }
};