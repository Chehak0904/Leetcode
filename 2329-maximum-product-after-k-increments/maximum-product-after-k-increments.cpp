class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        const int M = 1e9 + 7;
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());

        while (k--) {
            int ele = pq.top();
            pq.pop();
            pq.push(ele + 1);
        }

        long long ans = 1;
        while (!pq.empty()) {
            ans = (ans * pq.top()) % M;
            pq.pop();
        }

        return ans;
    }
};
