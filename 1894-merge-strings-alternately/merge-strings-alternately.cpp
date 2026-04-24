class Solution {
public:
    string mergeAlternately(string word1, string word2) {
       string res = "";
       
       int l1 = word1.size();
       int l2 = word2.size();

       for(int i = 0; i < l1 || i < l2; i++){
        if(i < l1){
            res = res + word1[i];
        }
        if(i < l2){
            res = res + word2[i];
        }
       }

       return res;
    }
};
