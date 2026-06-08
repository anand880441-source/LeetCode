class Solution {
public:
    int arrangeCoins(int n) {
        long long low = 0;
        long long high = n;
        int maxRows = 0;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long totalCoinsNeeded = mid * (mid + 1) / 2;
            
            if (totalCoinsNeeded == n) {
                return mid; 
            } else if (totalCoinsNeeded < n) {
                maxRows = mid;
                low = mid + 1;
            } else {
                high = mid - 1; 
            }
        }
        return maxRows;
    }
};
