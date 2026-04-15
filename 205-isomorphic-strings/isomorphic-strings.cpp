class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m1;
        unordered_map<char, char> m2;

        for (int i = 0; i < s.length(); i++) {
            char sc = s[i];
            char tc = t[i];

            if (m1.count(sc) && m1[sc] != tc){
                return false;
            };

            if (m2.count(tc) && m2[tc] != sc) {
                return false;
            };

            m1[sc] = tc;
            m2[tc] = sc;
        }
        return true;
    }
};