
class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.length();

        while (n > k) {
            string ans = "";
            int i = 0;
            int j = 0;

            while (j < n) {
                int sum = 0;

                while (j < n) {
                    sum += s[j] - '0';

                    if (j - i + 1 < k) {
                        j++;
                    }
                    else if (j - i + 1 == k) {
                        ans += to_string(sum);
                        j++;
                        i = j;
                        break;
                    }
                    else {
                        break;
                    }
                }

                if (j == n && i < n) {
                    ans += to_string(sum);
                    break;
                }
            }

            s = ans;
            n = s.length();
        }

        return s;
    }
};
