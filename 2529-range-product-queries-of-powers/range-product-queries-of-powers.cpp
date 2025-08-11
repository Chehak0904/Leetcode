class Solution {
public:
    int M=1e9+7;
     vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        int i = 0;
        while (n) {
            if (n & 1) {
                powers.push_back(pow(2, i));
            }
            i++;
            n = n >> 1;
        }
        int q = queries.size();
        vector<int> ans;
        for (int qi = 0; qi < q; qi++) {
            int x = queries[qi][0];
            int y = queries[qi][1];
            long long product = 1;
            for (int i = x; i <= y; i++) {
                product =(product*powers[i])%M;
            }

            ans.push_back(product);
        }
        return ans;
    }
};