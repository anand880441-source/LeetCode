class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        
        bool isNegative = num < 0;
        std::string result = "";
        long long n = abs(static_cast<long long>(num));
        
        while (n > 0) {
            result += to_string(n % 7);
            n /= 7;
        }
        
        if (isNegative) {
            result += '-';
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};