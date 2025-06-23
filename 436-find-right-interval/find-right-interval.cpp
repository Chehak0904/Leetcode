class Solution {
public:
    int find_right_interval(vector<vector<int>>&temp,int target,unordered_map<int,int>&mp){
        int ans=-1;
        int i=0;
        int j=temp.size()-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(temp[mid][0]>=target){
                j=mid-1;
                ans=mid;
            }
            else{
                i=mid+1;
            }
        }
        if(ans==-1){
            return -1;
        }
        return mp[temp[ans][0]];
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int>ans(n);
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[intervals[i][0]]=i;
        }
        vector<vector<int>>temp=intervals;
        sort(temp.begin(),temp.end());
        for(int i=0;i<n;i++){
            int t=find_right_interval(temp,intervals[i][1],mp);
            ans[i]=t;
            
        }
        return ans;

        
    }
};