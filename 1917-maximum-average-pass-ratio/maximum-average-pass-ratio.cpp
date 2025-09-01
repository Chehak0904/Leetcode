
class Solution {
public:
    double gain(int p, int t) { return (double)(p + 1) / (t + 1) - (double)p / t; }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int, int>>> pq;
        for ( auto c: classes) {
            int p = c[0], t = c[1];
            pq.push({gain(p, t), {p, t}});
        }

        while (extraStudents--) {
            auto [g, cls] = pq.top();
            pq.pop();
            int p = cls.first, t = cls.second;
            p++, t++;
            pq.push({gain(p, t), {p, t}});
        }

        double ans = 0.0;
        while (!pq.empty()) {
            auto [g, cls] = pq.top();
            pq.pop();
            int p = cls.first, t = cls.second;
            ans += (double)p / t;
        }
        return ans / classes.size();
    }
};
