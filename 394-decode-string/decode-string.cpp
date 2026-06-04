class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return answer(s, i);
    }

    string answer(string &s, int &i){
        string result = "";

        while(i < s.size() && s[i] != ']'){
            if(isalpha(s[i])){
                result += s[i];
                i++;
            }
            else if(isdigit(s[i])){
                int num = 0;
                while(i < s.size() && isdigit(s[i])){
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                
                ++i; 

                string temp = answer(s, i);

                ++i; 

                while(num--){
                    result += temp;
                }
            }
        }
        return result; 
    }
};
