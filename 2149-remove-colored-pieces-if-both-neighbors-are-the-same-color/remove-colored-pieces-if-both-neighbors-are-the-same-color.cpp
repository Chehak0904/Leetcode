class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0, b = 0;
        int len = 0;

        
        for (int i = 0; i < colors.size(); i++) {
            if (colors[i] == 'A') {
                len++;
            } else {
                if (len > 2) {
                    a += len - 2;
                }
                len = 0;
            }
        }
        
        if (len > 2) a += len - 2;

        
        len = 0;
        for (int i = 0; i < colors.size(); i++) {
            if (colors[i] == 'B') {
                len++;
            } else {
                if (len > 2) {
                    b += len - 2;
                }
                len = 0;
            }
        }
        
        if (len > 2) b += len - 2;

        return a > b;
    }
};
