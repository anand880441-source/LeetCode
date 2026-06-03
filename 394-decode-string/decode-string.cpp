class Solution {
public:
    string decodeString(string s) {
        stack<int> numSt;
        stack<string> strSt;
        int num = 0;
        string currentString = "";
        
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0'); 
            } 
            else if (s[i] == '[') { 
                strSt.push(currentString);
                numSt.push(num);    
                currentString = "";
                num = 0;
            } 
            else if (s[i] == ']') {
                string temp = currentString;
                currentString = strSt.top();
                strSt.pop();
                
                int count = numSt.top();
                numSt.pop();
                
                while (count--) {
                    currentString += temp;
                }
            } 
            else {
                currentString += s[i];
            }
        }
        
        return currentString;
    }
};