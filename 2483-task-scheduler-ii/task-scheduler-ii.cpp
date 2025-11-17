class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> mp;
        long long d = 0;
        for (int i = 0; i < tasks.size(); i++) {
            d++;
            if (mp.count(tasks[i])) {
                if (d < mp[tasks[i]]) {
                    d = mp[tasks[i]];
                }
            }
            mp[tasks[i]] = d + space + 1;
        }
        return d;
    }
};