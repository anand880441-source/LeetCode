class Solution {
public:
    int climbStairs(int n) {
        int totalWays = 0;
        
        for (int twos = 0; twos <= n / 2; twos++) {
            int ones = n - (2 * twos);
            int totalSteps = twos + ones;
            int r = twos;
            
            long long combinations = 1;
            for (int i = 1; i <= r; i++) {
                combinations = combinations * (totalSteps - r + i) / i;
            }
            
            totalWays += combinations;
        }
        
        return totalWays;
    }
};
