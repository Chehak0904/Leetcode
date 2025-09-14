class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }

    string convert_l(const string& s) {
        string temp = s;
        for (char& c : temp) c = tolower(c);
        return temp;
    }

    string convert_v(const string& s) {
        string temp;
        for (char c : s) {
            c = tolower(c);
            temp.push_back(isVowel(c) ? '*' : c);
        }
        return temp;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> st(wordlist.begin(), wordlist.end());
        unordered_map<string,string> mp_c, mp_v;

        for (const string& s : wordlist) {
            string lower = convert_l(s);
            string vowel = convert_v(s);
            if (!mp_c.count(lower)) mp_c[lower] = s;
            if (!mp_v.count(vowel)) mp_v[vowel] = s;
        }

        vector<string> ans;
        for (const string& q : queries) {
            if (st.count(q)) ans.push_back(q);
            else if (mp_c.count(convert_l(q))) ans.push_back(mp_c[convert_l(q)]);
            else if (mp_v.count(convert_v(q))) ans.push_back(mp_v[convert_v(q)]);
            else ans.push_back("");
        }
        return ans;
    }
};
