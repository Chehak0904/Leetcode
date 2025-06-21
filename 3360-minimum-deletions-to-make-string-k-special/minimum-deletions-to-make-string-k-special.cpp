class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int> freq;
        for(char c:word){
            freq[c]++;
        }
        vector<int> arr(26,-1);
        for(auto &it:freq){
            int c=it.first;
            arr[c-'a']=it.second;
        }
        
        int minDeletion=INT_MAX;;
        for(int i=0;i<26;i++){
            int cnt=0;
            if(arr[i]!=-1){
              for(int j=0;j<26;j++){
                if(arr[j]==-1 || j==i) continue;
                if(arr[j]<arr[i]){
                    cnt+=arr[j];
                }
                else if(abs(arr[j]-arr[i])>k){
                    cnt+=abs(arr[j]-arr[i])-k;
                }
              }
              minDeletion=min(minDeletion,cnt);
            }
            
        }
        return minDeletion;
    }
};