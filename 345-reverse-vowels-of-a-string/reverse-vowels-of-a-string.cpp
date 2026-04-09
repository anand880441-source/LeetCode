class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;
        string vowels = "aeiouAEIOU";

        while(i < j){
            if(vowels.find(s[i]) == -1){
                i++;
            }
            
            else if(vowels.find(s[j]) == -1){
                j--; 
            }

            else {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s; 
    }
};
