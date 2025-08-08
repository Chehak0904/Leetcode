class Solution {
public:
    int bs1(vector<int>& arr, int x) {
        int i = 0, j = arr.size() - 1, ans = -1;
        while (i <= j) {
            int m = j + (i - j) / 2;
            if (arr[m] < x) {
                ans = m;
                i = m + 1;
            } else {
                j = m - 1;
            }
        }
        return ans;
    }
    int bs2(vector<int>& arr, int x) {
        int i = 0, j = arr.size() - 1, ans = -1;
        while (i <= j) {
            int mid = j + (i - j) / 2;
            if (arr[mid] >= x) {
                ans = mid;
                j = mid - 1;
            }

            else {
                i = mid + 1;
            }
        }
        return ans;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int i = bs1(arr, x), j = bs2(arr, x);
        while (k--) {
            if (i >= 0 && j < arr.size()) {
                if (abs(arr[i] - x) < abs(arr[j] - x))
                    ans.push_back(arr[i--]);
                else if (abs(arr[j] - x) < abs(arr[i] - x))
                    ans.push_back(arr[j++]);
                else {
                    if (arr[i] < arr[j])
                        ans.push_back(arr[i--]);
                    else
                        ans.push_back(arr[j++]);
                }
            } else if (i >= 0)
                ans.push_back(arr[i--]);
            else if(j < arr.size())
                ans.push_back(arr[j++]);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};