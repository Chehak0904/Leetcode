class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1 && trust.empty()){
            return 1;
        }
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < trust.size(); i++) {
            int a = trust[i][0];
            int b = trust[i][1];
            mp[b].push_back(a);
        }
        for (auto it : mp) {
            if (it.second.size() == n - 1) {
                bool flag = false;
                for (int i = 0; i < trust.size(); i++) {
                    if (trust[i][0] == it.first) {
                        flag = true;
                    }
                }
                if (!flag)
                    return it.first;
            }
        }
        return -1;
    }
};