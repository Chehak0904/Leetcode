class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        unordered_set<long long> vis;

        pq.push(1);
        vis.insert(1);

        while (n--) {
            long long num = pq.top();
            pq.pop();

            if (n == 0)
                return num;

            for (long long x : {2, 3, 5}) {
                long long next = num * x;

                if (!vis.count(next)) {
                    vis.insert(next);
                    pq.push(next);
                }
            }
        }

        return -1;
    }
};