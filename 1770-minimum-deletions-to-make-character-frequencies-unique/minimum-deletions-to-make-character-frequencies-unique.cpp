class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> freq;
        for(char c:s){
            freq[c]++;
        }
        vector<int> arr;
        for(auto &it:freq){
            arr.push_back(it.second);
        }
        sort(arr.begin(),arr.end());
        unordered_set<int> st;
        int n=arr.size();
        st.insert(arr[0]);
        int cnt=0;
        for(int i=1;i<n;i++){
            while(st.find(arr[i])!=st.end()){
                arr[i]--;
                cnt++;
                if(arr[i]==0)break;
            }
            if(arr[i]!=0)st.insert(arr[i]);
        }
        return cnt;
    }
};