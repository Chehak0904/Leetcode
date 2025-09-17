class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string,long long> mp; 
        unordered_map<string,vector<pair<string,int>>> mp1; 

        for (int i = 0; i < creators.size(); i++) {
            mp[creators[i]] += views[i];
            mp1[creators[i]].push_back({ids[i], views[i]});
        }

        long long maxi = 0;
        for (auto &it : mp) {
            maxi = max(maxi, it.second);
        }

        vector<string> vec;
        for (auto &it : mp) {
            if (it.second == maxi) {
                vec.push_back(it.first);
            }
        }

        vector<vector<string>> ans;
        for (string &c : vec) {
            string temp = "";
            int v = -1;
            for (auto &p : mp1[c]) {
                string idx = p.first;
                int vo = p.second;
                if (vo > v || (vo == v && idx < temp)) {
                    temp = idx;
                    v = vo;
                }
            }
            ans.push_back({c, temp});
        }

        return ans;
    }
};
