class Solution {
public:
    string compressedString(string word) {
        string res = ""; 
        int count = 1; 
        
        for(int i = 0; i < word.length(); i++){ 
            if(i + 1 < word.length() && word[i] == word[i + 1]){ 
                count++; 
            } else { 
                while (count > 9) {
                    res += to_string(9);
                    res += word[i];
                    count -= 9;
                }
                res += to_string(count); 
                res += word[i]; 
                count = 1; 
            } 
        } 
        
        return res;
    }
};
