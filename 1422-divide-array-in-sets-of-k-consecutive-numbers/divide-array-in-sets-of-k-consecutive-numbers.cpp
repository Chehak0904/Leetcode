class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0) return false;
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int,int> mp;
        for (int num : nums) {
            mp[num]++;
            pq.push(num);
        }
         while (!pq.empty()) {
            int num = pq.top();
            pq.pop();
            if (mp.find(num) == mp.end()) continue;
            for (int i = 0; i < k; i++) {
                int curr = num + i;

                if (mp.find(curr) == mp.end()) 
                    return false; 

                mp[curr]--;
                if (mp[curr] == 0) mp.erase(curr);
            }
        }

        return true;
    }
};
