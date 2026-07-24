class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string sr = "";
        string tr = "";
        int count = 0;

        for(int i = 0; i<s.length(); i++){
            if(s[i] != '#'){
                sr = sr + s[i];
            }else if (!sr.empty()) {
                sr.pop_back();
            }
        }

        for(int i = 0; i<t.length(); i++){
            if(t[i] != '#'){
                tr = tr + t[i];
            }else if (!tr.empty()) {
                tr.pop_back();
            }
        }

        return sr == tr;
    }
};