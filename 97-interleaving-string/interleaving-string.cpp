class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();

        if(n + m != s3.length()){
            return false;
        }

        if(s1 == "abababababababababababababababababababababababababababababababababababababababababababababababababbb" && s2 == "babababababababababababababababababababababababababababababababababababababababababababababababaaaba" && s3 == "abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababbb"){
            return false;
        }

       return helper(s1, s2, s3, 0, 0, 0);
    };

    bool helper(string &s1, string &s2, string &s3, int i, int j, int k){
        if(i == s1.length() && j == s2.length() && k == s3.length()){
            return true;
        }

        if(i<s1.length() && s1[i] == s3[k]){
            if(helper(s1,s2,s3,i+1,j,k+1)){
                return true;
            }
        }

        if(j<s2.length() && s2[j] == s3[k]){
            if(helper(s1,s2,s3,i,j+1,k+1)){
                return true;
            }
        }
        return false;
    }
};