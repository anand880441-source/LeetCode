class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> cIndex;
        vector<int> result(s.length());
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == c){
                cIndex.push_back(i);
            }
        }

        for(int i = 0; i < s.length(); i++){
            int minDistance = s.length(); 
           
            for(int j = 0; j < cIndex.size(); j++) {
                int currentDistance = abs(i - cIndex[j]); 
                
                if(currentDistance < minDistance) {
                    minDistance = currentDistance; 
                }
            }
            result[i] = minDistance; 
        }
        
        return result;
    }
};
