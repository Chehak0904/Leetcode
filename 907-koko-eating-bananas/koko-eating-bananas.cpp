class Solution {
public:
    bool isPossible(vector<int>& piles, int k, int h) {
        int hr = 0;
        for (int i = 0; i < piles.size(); i++) {
            hr += piles[i] / k;
            if(hr>h) return false;
             if (piles[i] % k != 0) { hr++; }
        }
        return hr <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        int ans = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (isPossible(piles,m,h)) {
                ans = m;
                r = m - 1;

            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};