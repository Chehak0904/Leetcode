class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> s;
        
        for(int i=0;i<friendships.size();i++ ){
            int u = friendships[i][0] - 1;
            int v = friendships[i][1] - 1;
            
            unordered_set<int> st(languages[u].begin(), languages[u].end());
            bool flag = false;
            
            for(int lang : languages[v]){
                if(st.find(lang) != st.end()){
                    flag = true; 
                    break;
                }
            }
            
            if(!flag){ 
                s.insert(u);
                s.insert(v);
            }
        }
        
        unordered_map<int,int> cnt;
        int maxCount = 0;
        
        for(auto it : s){
            for(int lang : languages[it]){
                cnt[lang]++;
                maxCount = max(maxCount, cnt[lang]);
            }
        }
        
        return s.size() - maxCount;
    }
};
