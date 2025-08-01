class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> vec(n, 0);
        for (auto& road : roads) {
            vec[road[0]]++;
            vec[road[1]]++;
        }
        vector<pair<int, int>> temp;
        for (int i = 0; i < vec.size(); i++) {
            temp.push_back({vec[i], i});
        }
        sort(temp.begin(), temp.end(),greater<>());
        int num = n;
        for (auto& [freq, node] : temp) {
            vec[node] = num--;
        }

        long long ans = 0;
        for (auto& road : roads) {
            ans += vec[road[0]] + vec[road[1]];
        }
        return ans;
    }
};