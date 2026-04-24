class Solution {
public:
    bool isPalindrome(string s) {
        string res = "";

        for(int i = 0; i < s.size(); i++){
            char c = s[i];
    
            if (c >= 'A' && c <= 'Z') {
                res += (c + 32); 
            } 
            else if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
                res += c;
            } 
        }

        string rev(res.rbegin(), res.rend());

        return res == rev;
    }
};