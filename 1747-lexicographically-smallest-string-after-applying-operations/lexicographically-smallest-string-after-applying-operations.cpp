class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> vis;
        queue<string> q;
        q.push(s);
        vis.insert(s);

        string ans = s;

        while (!q.empty()) {
            string temp = q.front();
            q.pop();
            ans = min(ans, temp);
            string addOp = temp;
            for (int i = 1; i < s.size(); i += 2) {
                addOp[i] = ((addOp[i] - '0' + a) % 10) + '0';
            }
            if (!vis.count(addOp)) {
                vis.insert(addOp);
                q.push(addOp);
            }
            string rotateOp =
                temp.substr(temp.size() - b) + temp.substr(0, temp.size() - b);
            if (!vis.count(rotateOp)) {
                vis.insert(rotateOp);
                q.push(rotateOp);
            }
        }
        return ans;
    }
};
