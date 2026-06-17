class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int rCount=0;
        int lCount = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == 'R') rCount++;
            if(s[i] == 'L') lCount++;
            if(rCount == lCount) {
                count++;
                rCount=0;
                lCount=0;
            }
        }
        return count;
    }
};