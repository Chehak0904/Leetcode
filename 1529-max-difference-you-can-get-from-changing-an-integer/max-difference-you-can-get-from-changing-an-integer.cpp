class Solution {
public:
    int maxDiff(int num) {
        string temp = to_string(num);

        
        char ch1 = '$';
        for (int i = 0; i < temp.length(); i++) {
            if (temp[i] != '9') {
                ch1 = temp[i];
                break;
            }
        }

       
        char ch2 = '$';
        if (temp[0] != '1') {
            ch2 = temp[0];
        } else {
            for (int i = 1; i < temp.length(); i++) {
                if (temp[i] != '0' && temp[i] != '1') {
                    ch2 = temp[i];
                    break;
                }
            }
        }

        string a = temp;
        string b = temp;

      
        if (ch1 != '$') {
            for (int i = 0; i < a.length(); i++) {
                if (a[i] == ch1) {
                    a[i] = '9';
                }
            }
        }

        
        if (ch2 != '$') {
            char replaceChar = (ch2 == temp[0]) ? '1' : '0';
            for (int i = 0; i < b.length(); i++) {
                if (b[i] == ch2) {
                    b[i] = replaceChar;
                }
            }
        }

        return stoi(a) - stoi(b);
    }
};
