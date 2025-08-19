#include <deque>
using namespace std;

class DataStream {
public:
    deque<int> q;
    int k;
    int v;

    DataStream(int value, int k_) {
        v=value;
        k = k_;
    }

    bool consec(int num) {
        if (!q.empty() && num != q.back()) {
            q.clear();
        }
        if (num == v) {
            q.push_back(num);
        }

        if (q.size() > k) {
            q.pop_front();
        }

        return q.size() == k;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */